CPROGS := check_dep
GENERATED := zconf.hash.c zconf.tab.c zconf.lex.c

.PHONY: all clean configure clobber check-dep

all: $(GENERATED) $(CPROGS)

zconf.tab.o: zconf.tab.c zconf.hash.c zconf.lex.c util.c confdata.c expr.c symbol.c menu.c lkc.h

bconf.tab.o: bconf.tab.c bconf.lex.c

check_dep: check_dep.o zconf.tab.o bconf.tab.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

zconf.hash.c: zconf.gperf
	gperf -t --output-file $@ -a -C -E -g -k '1,3,$$' -p -t $<

%.tab.c: %.y
	bison -l -b $* -p $* -t $<

%.lex.c: %.l
	flex -o $@ $<

clean:
	$(RM) $(CPROGS) *.o

clobber:
	$(RM) $(GENERATED)
