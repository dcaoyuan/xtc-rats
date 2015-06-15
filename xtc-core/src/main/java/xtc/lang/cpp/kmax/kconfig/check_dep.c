#include <locale.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/time.h>

#include "lkc.h"

#define fopen(name, mode) ({                    \
      if (verbose)                              \
        printf("opening %s\n", name);           \
      fopen(name, mode);                        \
    })

#define truncate(str, len) ({                   \
      if (verbose)                              \
        printf("deleting %s\n", str);           \
      truncate(str, len);                       \
    })

static char *progname;
enum {
  A_NONE,
  A_CONFIGS,
  A_KCONFIGS,
  A_MENUSYMS,
  A_DEFAULTS,
  A_SYMDEPS,
  A_DEFDEPS,
  A_EVERYYES,
  A_EVERYNO,
  A_EVERYDEF,
  A_EVERYYESI,
  A_SEARCH,
  A_DEPSYM,
  A_IDEPSYM,
  A_NONBOOLS,
  A_BOOLS,
  A_TRISTATE,
  A_DEPS,
  A_DUMP,
};
static int action = A_NONE;
static char* action_arg;
static bool bconf_parser = false;
static bool default_env = false;
static bool verbose = false;
static char* forceoff = NULL;

struct linked_list {
  struct linked_list *next;
  void *data;
};

static struct linked_list *forceoffall = NULL;

bool check_symbol(struct symbol *, char *);
bool find_dep(struct expr *, char *);
void print_deps(struct symbol *);
void print_deps_expr(struct expr *);
bool defdeps(struct symbol *);
bool defdeps_expr(struct expr *);
bool depsym(struct symbol *);
bool depsym_expr(struct expr *);
bool idepsym(struct symbol *);
bool idepsym_expr(struct expr *);
bool is_symbol(struct symbol *);

/*
 * See whether the symbol's direct or reverse dependency expressions
 * contain the configuration variable name.
 */
bool check_symbol(struct symbol *sym, char *name)
{
  if (!sym->name || strlen(sym->name) == 0)
    return false;
  if (!strcmp(sym->name, name))
    return true;
  if (sym->searched)
    return sym->depends;

  // need to check for circular dependencies first.
  sym->searched = true;
  if (!sym->dir_dep.expr)
    sym->depends = false;
  else
    sym->depends = find_dep(sym->dir_dep.expr, name);
  if (sym->rev_dep.expr)
    sym->depends = sym->depends || find_dep(sym->rev_dep.expr, name);

  if (sym->depends)
    printf("%s\n", sym->name);
  return sym->depends;
}

/*
 * See whether an expression contains the configuration variable name.
 * Recursively search in symbols referenced in the expression.
 */
bool find_dep(struct expr *e, char *name)
{
  struct expr *left, *right;
  struct symbol *sym;

  left = e->left.expr;
  right = e->right.expr;
  sym = e->left.sym;

	switch (e->type) {
	case E_SYMBOL:
	case E_EQUAL:
	case E_UNEQUAL:
    return check_symbol(sym, name);

	case E_NOT:
    return find_dep(left, name);

	case E_OR:
    return find_dep(left, name) || find_dep(right, name);

	case E_AND:
    return find_dep(left, name) && find_dep(right, name);

	/* case E_LIST: */
  /*   //E_LIST is created in menu_finalize and is related to <choice> */
  /*   printf("%s ", e->right.sym->name); */
	/* 	if (e->left.expr) { */
  /*     printf("^ "); */
  /*     expr_to_bdd(e->left.expr); */
	/* 	} */
	/* 	break; */
	/* case E_RANGE: */
  /*   printf("["); */
  /*   printf("%s ", e->left.sym->name); */
  /*   printf("%s", e->right.sym->name); */
  /*   printf("]"); */
	/* 	break; */

  default:
    fprintf(stderr, "error: invalid expression type\n");
    exit(1);
	}
}

void print_expr(struct expr *e, FILE *out, enum expr_type prevtoken)
{
	if (expr_compare_type(prevtoken, e->type) > 0)
		fprintf(out, "(");
	switch (e->type) {
	case E_SYMBOL:
		if (e->left.sym->name)
      fprintf(out, "%s", e->left.sym->name);
		else
      fprintf(out, "<choice>", e->left.sym->name);
		break;
	case E_NOT:
    fprintf(out, "!");
    print_expr(e->left.expr, out, E_NOT);
		break;
	case E_EQUAL:
		if (e->left.sym->name)
      fprintf(out, "%s", e->left.sym->name);
		else
      fprintf(out, "<choice> ", e->left.sym->name);
    fprintf(out, "=%s", e->right.sym->name);
		break;
	case E_UNEQUAL:
		if (e->left.sym->name)
      fprintf(out, "%s", e->left.sym->name);
		else
      fprintf(out, "<choice> ", e->left.sym->name);
    fprintf(out, "!=%s", e->right.sym->name);
		break;
	case E_OR:
    print_expr(e->left.expr, out, E_OR);
    fprintf(out, " || ");
    print_expr(e->right.expr, out, E_OR);
		break;
	case E_AND:
    print_expr(e->left.expr, out, E_AND);
    fprintf(out, " && ");
    print_expr(e->right.expr, out, E_AND);
		break;
	case E_LIST:
    //E_LIST is created in menu_finalize and is related to <choice>
    fprintf(out, "%s ", e->right.sym->name);
		if (e->left.expr) {
      fprintf(out, "^ ");
      print_expr(e->left.expr, out, E_LIST);
		}
		break;
	case E_RANGE:
    fprintf(out, "[");
    fprintf(out, "%s ", e->left.sym->name);
    fprintf(out, "%s", e->right.sym->name);
    fprintf(out, "]");
		break;
	/* default: */
	/*   { */
	/* 	char buf[32]; */
	/* 	sprintf(buf, "<unknown type %d>", e->type); */
	/* 	fn(data, NULL, buf); */
	/* 	break; */
	/*   } */
	}
	if (expr_compare_type(prevtoken, e->type) > 0)
		fprintf(out, ")");
}

static inline int expr_is_mod(struct expr *e)
{
	return !e || (e->type == E_SYMBOL && e->left.sym == &symbol_mod);
}

/*
 * See whether the symbol is a default.  Defaults are configuration
 * variables that are non-visible (i.e., have no user prompts), have
 * an always-true default, and do not have any reverse dependencies.
 */
bool is_default(struct symbol *sym)
{
  struct property *st;

  for_all_prompts(sym, st)
    return false;

  if (sym->rev_dep.expr && !expr_is_yes(sym->rev_dep.expr))
    return false;

  for_all_defaults(sym, st) {
    if (!st->visible.expr || expr_is_yes(st->visible.expr))
      if (expr_is_yes(st->expr) || expr_is_mod(st->expr))
        return true;
  }

  return false;
}

/* Always return false.  Used for the --everyno action. */
bool never(struct symbol *sym)
{
  return false;
}

/* Negate idepsym.  Used for the --everyyesi action. */
bool inverse(struct symbol *sym)
{
  return !idepsym(sym);
}

/* Check whether a configuration variable should be forced to off */
bool check_forceoff(struct symbol *sym)
{
  struct linked_list *p;

  for (p = forceoffall; p != NULL; p = p->next)
    if (!strcmp(p->data, sym->name))
      return true;

  return NULL != forceoff && !strcmp(forceoff, sym->name);
}

/* Write out the Linux configuration files, setting all configuration
 * variables to yes.
 */
void write_config(bool (*in_config)(struct symbol *))
{
  char *config_prefix = !bconf_parser ? "CONFIG_" : "";
  struct symbol *sym;
  int i;

  FILE *allvars;
  FILE *conf;
  FILE *autoconf;
  FILE *tristate;
  FILE *header;

  allvars = fopen(".allvars", "w");
  if (!allvars) {
    perror("fopen");
    exit(1);
  }

  conf = fopen(".config", "w");
  if (!conf) {
    perror("fopen");
    exit(1);
  }

  if (mkdir("include/config/", S_IRWXU)) {
    if (EEXIST != errno) {
      perror("mkdir");
      exit(1);
    }
  }

  autoconf = fopen("include/config/auto.conf", "w");
  if (!autoconf) {
    perror("fopen");
    exit(1);
  }

  tristate = fopen("include/config/tristate.conf", "w");
  if (!tristate) {
    perror("fopen");
    exit(1);
  }

  if (mkdir("include/generated/", S_IRWXU)) {
    if (EEXIST != errno) {
      perror("mkdir");
      exit(1);
    }
  }

  if (!bconf_parser)
    header = fopen("include/generated/autoconf.h", "w");
  else
    header = fopen("include/linux/autoconf.h", "w");
  if (!header) {
    perror("fopen");
    exit(1);
  }

  conf_set_all_new_symbols(def_yes);
  for_all_symbols(i, sym) {
    if (!sym)
      continue;
    if (!sym->name)
      continue;
    sym_calc_value(sym);
  }

  for_all_symbols(i, sym) {
    const char *str;

    if (!sym)
      continue;
    if (!sym->name)
      continue;
    if (!is_symbol(sym))
      continue;
    if (!(*in_config)(sym))
      continue;
    if (check_forceoff(sym))
      continue;

    switch (sym->type) {
    case S_OTHER:
    case S_UNKNOWN:
      break;
    case S_STRING:
      str = sym_get_string_value(sym);
      str = sym_escape_string_value(str);
      fprintf(allvars, "%s\n", sym->name);
      fprintf(conf, "%s%s=%s\n", config_prefix, sym->name, str);
      fprintf(autoconf, "%s%s=%s\n", config_prefix, sym->name, str);
      free((void *)str);
      break;
    case S_BOOLEAN:
    case S_TRISTATE:
      fprintf(allvars, "%s\n", sym->name);
      fprintf(conf, "%s%s=y\n", config_prefix, sym->name);
      fprintf(autoconf, "%s%s=y\n", config_prefix, sym->name);
      fprintf(tristate, "%s%s=Y\n", config_prefix, sym->name);
      break;
    default:
      fprintf(allvars, "%s\n", sym->name);
      fprintf(conf, "%s%s=%s\n", config_prefix, sym->name, sym->curr.val);
      fprintf(autoconf, "%s%s=%s\n", config_prefix, sym->name, sym->curr.val);
      break;
    }
  }

  for_all_symbols(i, sym) {
    const char *str;

    if (!sym)
      continue;
    if (!sym->name)
      continue;
    if (!is_symbol(sym))
      continue;
    if (!(*in_config)(sym))
      continue;
    if (check_forceoff(sym))
      continue;

    switch (sym->type) {
    case S_BOOLEAN:
    case S_TRISTATE: {
      fprintf(header, "#define %s%s 1\n", config_prefix, sym->name);
      break;
    }
    case S_HEX: {
      const char *prefix = "";

      str = sym_get_string_value(sym);
      if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
        prefix = "0x";

      fprintf(header, "#define %s%s %s%s\n", config_prefix, sym->name, prefix, str);
      break;
    }
    case S_STRING:
      str = sym_get_string_value(sym);
      str = sym_escape_string_value(str);
      fprintf(header, "#define %s%s %s\n", config_prefix, sym->name, str);
      free((void *)str);
      break;
    case S_INT:
      str = sym_get_string_value(sym);
      fprintf(header, "#define %s%s %s\n", config_prefix, sym->name, str);
      break;
    default:
      break;
    }
  }

  if (fclose(allvars)) {
    perror("fclose");
    exit(1);
  }

  if (fclose(conf)) {
    perror("fclose");
    exit(1);
  }

  if (fclose(autoconf)) {
    perror("fclose");
    exit(1);
  }

  if (fclose(tristate)) {
    perror("fclose");
    exit(1);
  }

  if (fclose(header)) {
    perror("fclose");
    exit(1);
  }
}

/* Write out the config files with no configuration variables set */
void everyno(void)
{
  char *cfiles[] = { ".config",
                     "include/config/auto.conf.cmd",
                     "include/config/auto.conf",
                     "include/config/tristate.conf" };
  char *zfiles[] = { "include/generated/autoconf.h",
                     "include/config/auto.conf.cmd" };
  char *bfiles[] = { "include/linux/autoconf.h" };
  int i;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))

  for (i = 0; i < ARRAY_SIZE(cfiles); i++)
    if (truncate(cfiles[i], 0))
      perror("truncate");

  if (!bconf_parser)
    for (i = 0; i < ARRAY_SIZE(zfiles); i++)
      if (truncate(zfiles[i], 0))
        perror("truncate");
  else
    for (i = 0; i < ARRAY_SIZE(bfiles); i++)
      if (truncate(bfiles[i], 0))
        perror("truncate");

}

/* Print the list of symbols that the given symbol depends on. */
void print_deps(struct symbol *sym)
{
  if (!sym->name || strlen(sym->name) == 0)
    return;
  if (sym->searched)
    return;

  printf("%s,", sym->name);

  sym->searched = true;
  if (sym->dir_dep.expr)
    print_deps_expr(sym->dir_dep.expr);
  if (sym->rev_dep.expr)
    print_deps_expr(sym->rev_dep.expr);
}

void print_deps_expr(struct expr *e)
{
  struct expr *left, *right;
  struct symbol *sym;

  left = e->left.expr;
  right = e->right.expr;
  sym = e->left.sym;

	switch (e->type) {
	case E_SYMBOL:
	case E_EQUAL:
	case E_UNEQUAL:
    print_deps(sym);
    return;

	case E_NOT:
    print_deps_expr(left);
    return;

	case E_OR:
	case E_AND:
    print_deps_expr(left);
    print_deps_expr(right);
    return;

  default:
    fprintf(stderr, "error: invalid expression type\n");
    exit(1);
	}
}

bool defdeps(struct symbol *sym)
{
  if (!sym->name || strlen(sym->name) == 0)
    return true;
  if (sym->searched)
    return sym->depends;

  sym->searched = true;
  if (is_default(sym)) {
    sym->depends = true;
    return true;
  }

  if (!sym->dir_dep.expr && !sym->rev_dep.expr) {
    sym->depends = false;
    return false;
  }

  sym->depends = true;
  if (sym->dir_dep.expr)
    sym->depends = sym->depends && defdeps_expr(sym->dir_dep.expr);
  if (sym->rev_dep.expr)
    sym->depends = sym->depends && defdeps_expr(sym->rev_dep.expr);

  return sym->depends;
}

/*
 * See whether an expression contains the configuration variable name.
 * Recursively search in symbols referenced in the expression.
 */
bool defdeps_expr(struct expr *e)
{
  struct expr *left, *right;
  struct symbol *sym;

  left = e->left.expr;
  right = e->right.expr;
  sym = e->left.sym;

	switch (e->type) {
	case E_SYMBOL:
	case E_EQUAL:
	case E_UNEQUAL:
    return false;

	case E_NOT:
    return defdeps_expr(left);

	case E_OR:
    return defdeps_expr(left) && defdeps_expr(right);

	case E_AND:
    return defdeps_expr(left) && defdeps_expr(right);

  default:
    fprintf(stderr, "error: invalid expression type\n");
    exit(1);
	}
}

/* Returns true when the sym's dependencies only depend on
 * non-architectural configuration variables.
 */
bool depsym(struct symbol *sym)
{
  if (!sym->name || strlen(sym->name) == 0)
    return false;
  if (sym->searched)
    return sym->depends;

  if (strcmp(sym->name, "y") == 0)
    return false;
  else if (strcmp(sym->name, "m") == 0)
    return false;
  else if (strcmp(sym->name, "n") == 0)
    return false;

  if (sym->dir_dep.expr == NULL && sym->rev_dep.expr == NULL
      && is_symbol(sym)) {
    sym->searched = true;
    sym->depends = false;
    return sym->depends;
  }

  sym->searched = true;
  sym->depends = true;
  if (sym->dir_dep.expr) {
    sym->depends = sym->depends && depsym_expr(sym->dir_dep.expr);
  }
  if (sym->rev_dep.expr) {
    sym->depends = sym->depends && depsym_expr(sym->rev_dep.expr);
  }

  return sym->depends;
}

bool depsym_expr(struct expr *e)
{
  struct expr *left, *right;
  struct symbol *sym;

  left = e->left.expr;
  right = e->right.expr;
  sym = e->left.sym;

	switch (e->type) {
	case E_SYMBOL:
	case E_EQUAL:
	case E_UNEQUAL:
    return depsym(sym);

	case E_NOT:
    return false;

	case E_OR:
    return depsym_expr(left) && depsym_expr(right);

	case E_AND:
    return depsym_expr(left) || depsym_expr(right);

  default:
    fprintf(stderr, "error: invalid expression type\n");
    exit(1);
	}
}

/* Returns true when the sym is selectable
 */
bool idepsym(struct symbol *sym)
{
  if (!sym->name || strlen(sym->name) == 0)
    return true;
  if (sym->searched)
    return sym->depends;

  if (strcmp(sym->name, "y") == 0)
    return true;
  else if (strcmp(sym->name, "m") == 0)
    return true;
  else if (strcmp(sym->name, "n") == 0)
    return true;

  if (sym->dir_dep.expr == NULL && sym->rev_dep.expr == NULL
      && is_symbol(sym)) {
    sym->searched = true;
    sym->depends = true;
    return sym->depends;
  }

  sym->searched = true;
  sym->depends = false;
  if (sym->dir_dep.expr) {
    sym->depends = sym->depends || idepsym_expr(sym->dir_dep.expr);
  }
  if (sym->rev_dep.expr) {
    sym->depends = sym->depends || idepsym_expr(sym->rev_dep.expr);
  }

  return sym->depends;
}

bool idepsym_expr(struct expr *e)
{
  struct expr *left, *right;
  struct symbol *sym;

  left = e->left.expr;
  right = e->right.expr;
  sym = e->left.sym;

	switch (e->type) {
	case E_SYMBOL:
	case E_EQUAL:
	case E_UNEQUAL:
    return idepsym(sym);

	case E_NOT:
    return true;

	case E_OR:
    return idepsym_expr(left) || idepsym_expr(right);

	case E_AND:
    return idepsym_expr(left) && idepsym_expr(right);

  default:
    fprintf(stderr, "error: invalid expression type\n");
    exit(1);
	}
}

bool is_symbol(struct symbol *sym)
{
  struct property *st;

  for_all_properties(sym, st, P_SYMBOL)
    return true;
  return false;
}

void print_menusyms(struct menu *m)
{
  while (m) {
    if (m->sym && m->sym->name && strlen(m->sym->name) > 0)
      printf("%s\n", m->sym->name);
    if (m->list)
      print_menusyms(m->list);
    m = m->next;
  }
}

void print_usage(void)
{
  printf("USAGE\n");
  printf("%s [options] --ACTION Kconfig\n", progname);
  printf("\n");
  printf("OPTIONS\n");
  printf("-C, --Configure\tparse config.in files instead of Kconfig\n");
  printf("-d, --default-env\tuse x86 environment variables\n");
  printf("                 \tSRCARCH=x86 ARCH=x86_64 KERNELVERSION=kcu\n");
  printf("-f, --forceoff var\tturn off var (only for --every* actions)\n");
  printf("-a, --forceoffall file\tturn off all vars in file\n");
  printf("-v, --verbose\t\tverbose output\n");
  printf("-h, --help\t\tdisplay this help message\n");
  printf("\n");
  printf("ACTIONS\n");
  printf("--depsym\tprint all config vars that depend on arch\n");
  printf("--idepsym\tprint all config vars that depend on arch\n");
  printf("--tristate\tprint all tristate config vars that depend on arch\n");
  printf("--bools\tprint all boolean config vars that depend on arch\n");
  printf("--nonbools\tprint all non-boolean config vars that depend on arch\n");
  printf("--configs\tprint all config vars\n");
  printf("--kconfigs\tprint all config vars declared in kconfig files\n");
  printf("--menusyms\t"
         "print config vars declared in the Kconfig files (using menus)\n");
  printf("--everyyes\t"
         "output linux config files with all config vars set to yes\n");
  printf("--everyno\t"
         "output linux config files with all config vars set to no\n");
  printf("--everydef\t"
         "output linux config files with only root config vars set to yes\n");
  printf("--everyyesi\t"
         "output linux config files the inverse of everyyes\n");
  printf("--defaults\tprint all configuration variables that are defaults\n");
  printf("--defdeps\t"
         "print all defaults and config vars that only depend on defaults\n");
  printf("--symdeps\t"
         "for each config var, list the config vars on which it depends\n");
  printf("--search VAR\tfind all config vars that depend on VAR\n");
  printf("--deps VAR\tprint direct and reverse dependencies for VAR\n");
  printf("--dump\t\tdump configuration variables\n");
  printf("\n");
  exit(0);
}

int main(int argc, char **argv)
{
  int opt;
  char *kconfig;
  struct symbol *sym;
  int i;
  char *name;

  progname = argv[0];

  if (1 == argc)
    print_usage();

	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

  opterr = 0;
  while (1) {
    static struct option long_options[] = {
      {"depsym", no_argument, &action, A_DEPSYM},
      {"idepsym", no_argument, &action, A_IDEPSYM},
      {"nonbools", no_argument, &action, A_NONBOOLS},
      {"bools", no_argument, &action, A_BOOLS},
      {"tristate", no_argument, &action, A_TRISTATE},
      {"configs", no_argument, &action, A_CONFIGS},
      {"kconfigs", no_argument, &action, A_KCONFIGS},
      {"menusyms", no_argument, &action, A_MENUSYMS},
      {"defaults", no_argument, &action, A_DEFAULTS},
      {"symdeps", no_argument, &action, A_SYMDEPS},
      {"defdeps", no_argument, &action, A_DEFDEPS},
      {"everyyes", no_argument, &action, A_EVERYYES},
      {"everyno", no_argument, &action, A_EVERYNO},
      {"everydef", no_argument, &action, A_EVERYDEF},
      {"everyyesi", no_argument, &action, A_EVERYYESI},
      {"forceoff", required_argument, 0, 'f'},
      {"forceoffall", required_argument, 0, 'a'},
      {"search", required_argument, &action, A_SEARCH},
      {"deps", required_argument, &action ,A_DEPS},
      {"dump", no_argument, &action ,A_DUMP},
      {"Configure", no_argument, 0, 'C'},
      {"default-env", no_argument, 0, 'd'},
      {"verbose", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}
    };

    int option_index = 0;

    opt = getopt_long(argc, argv, "Cdhf:a:v", long_options, &option_index);

    if (-1 == opt)
      break;

    FILE *tmp;
    char *line;
    size_t len;
    ssize_t read;
    struct linked_list *last;

    switch (opt) {
    case 0:
      action_arg = optarg;
      break;
    case 'f':
      forceoff = optarg;
      break;
    case 'a':
      tmp = fopen(optarg, "r");
      line = NULL;
      len = 0;

      if (!tmp) {
        perror("fopen");
        exit(1);
      }

      last = NULL;
      while ((read = getline(&line, &len, tmp)) != -1) {
        struct linked_list *tmp = malloc(sizeof(struct linked_list));
        char *p;

        for (p = line; *p != '\0'; p++)
          if (*p == '\n') {
            *p = '\0';
            break;
          }

        tmp->next = NULL;
        tmp->data = line;
        /* printf("%s\n", line); */
        if (NULL == last) {
          last = forceoffall = tmp;
        } else {
          last->next = tmp;
          last = tmp;
        }
        line = NULL;  //force getline to allocate a new buffer
      }
      fclose(tmp);
      break;
    case 'C':
      bconf_parser = true;
      break;
    case 'd':
      default_env = true;
      break;
    case 'v':
      verbose = true;
      break;
    case 'h':
      print_usage();
      break;
    case ':':
    case '?':
      fprintf(stderr, "Invalid option or missing argument.  For help use -h\n");
      exit(1);
      break;
    }
  }

  if (A_NONE == action) {
    fprintf(stderr, "Please specify an action.  For help use -h.\n");
    exit(1);
  }

  if (default_env) {
    putenv("SRCARCH=x86");
    putenv("ARCH=x86_64");
    putenv("KERNELVERSION=kcu");
  }

  if (optind < argc)
    kconfig = argv[optind++];
  else
    kconfig = "Kconfig";

  if (bconf_parser) {
    bconf_parse(kconfig);
  } else {
    conf_parse(kconfig);
  }

  switch (action) {
  case A_SEARCH:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      check_symbol(sym, action_arg);
    break;
  case A_DEFAULTS:
    for_all_symbols(i, sym) {
      static bool def;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      def = is_default(sym);
      if (def)
        printf("%s\n", sym->name);
    }
    break;
  case A_CONFIGS:
    for_all_symbols(i, sym) {
      if (!sym->name || strlen(sym->name) == 0)
        continue;

      printf("%s\n", sym->name);
    }
    break;
  case A_KCONFIGS:
    for_all_symbols(i, sym) {
      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (is_symbol(sym))
        printf("%s\n", sym->name);
    }
    break;
  case A_EVERYYES:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }
    for_all_symbols(i, sym)
      idepsym(sym);
    write_config(idepsym);
    if (!bconf_parser) file_write_dep("include/config/auto.conf.cmd");
    break;
  case A_EVERYNO:
    write_config(never);
    break;
  case A_EVERYDEF:
    write_config(is_default);
    break;
  case A_EVERYYESI:
    write_config(inverse);
    break;
  case A_SYMDEPS:
    for_all_symbols(i, sym) {
      int i2;
      struct symbol *sym2;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      for_all_symbols(i2, sym2) {
        sym->searched = false;
      }

      printf("%s=", sym->name);
      print_deps(sym);
      printf("\n");
    }
    break;
  case A_DEFDEPS:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      defdeps(sym);

    for_all_symbols(i, sym) {

      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (dep)
        printf("%s\n", sym->name);
    }
    break;
  case A_MENUSYMS:
    print_menusyms(rootmenu.list);
    break;
  case A_DEPSYM:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      depsym(sym);

    for_all_symbols(i, sym) {
      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (!dep)
        printf("%s\n", sym->name);
    }
    break;
  case A_IDEPSYM:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      idepsym(sym);

    for_all_symbols(i, sym) {
      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (dep)
        printf("%s\n", sym->name);
    }
    break;
  case A_NONBOOLS:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      idepsym(sym);

    for_all_symbols(i, sym) {
      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (dep && sym->type != S_BOOLEAN && sym->type != S_TRISTATE)
        printf("%s\n", sym->name);
    }
    break;
  case A_BOOLS:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      idepsym(sym);

    for_all_symbols(i, sym) {
      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (dep && sym->type == S_BOOLEAN)
        printf("%s\n", sym->name);
    }
    break;
  case A_TRISTATE:
    for_all_symbols(i, sym) {
      sym->searched = false;
      sym->depends = false;
    }

    for_all_symbols(i, sym)
      idepsym(sym);

    for_all_symbols(i, sym) {
      bool dep = sym->depends;

      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (dep && sym->type == S_TRISTATE)
        printf("%s\n", sym->name);
    }
    break;
  case A_DEPS:
    for_all_symbols(i, sym) {
      if (!sym->name || strlen(sym->name) == 0)
        continue;

      if (strcmp(sym->name, action_arg) == 0) {
        printf("dir_dep: ");
        if (sym->dir_dep.expr)
          print_expr(sym->dir_dep.expr, stdout, E_NONE);
        printf("\n");

        printf("rev_dep: ");
        if (sym->rev_dep.expr)
          print_expr(sym->rev_dep.expr, stdout, E_NONE);
        printf("\n");

        printf("in arch? %s\n", idepsym(sym) ? "yes" : "no");
      }
    }
    break;
  case A_DUMP:
    zconfdump(stdout);
    break;
  default:
    fprintf(stderr, "fatal error: unsupported action\n");
    exit(1);
    break;
  }

  return 0;
}
