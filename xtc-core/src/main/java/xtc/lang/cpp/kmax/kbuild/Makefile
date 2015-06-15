TMPDIR := /tmp
PYMAKE := http://hg.mozilla.org/users/bsmedberg_mozilla.com/pymake/archive/default.tar.bz2

all: pymake/ make/

pymake/:
ifeq ($(shell which wget > /dev/null; echo $$?), 0)
	wget -P $(TMPDIR) $(PYMAKE)
else
ifeq ($(shell which curl > /dev/null; echo $$?), 0)
	curl $(PYMAKE) > $(TMPDIR)/default.tar.bz2
else
	@echo "No download tool found.  Need wget or curl."
	@false
endif
endif
	tar -jxvf $(TMPDIR)/default.tar.bz2 -C $(TMPDIR)
	mv $(TMPDIR)/pymake-default/pymake .
	$(RM) $(TMPDIR)/default.tar.bz2
	$(RM) -R $(TMPDIR)/pymake-default

make/:
	git clone git://git.savannah.gnu.org/make.git make
	(cd make/ && git checkout 450b7e1a3d3f0b9c84f9b8f6909fa844afacbec5 && git apply ../make.patch)

clobber:
	$(RM) -R pymake/
	$(RM) -R make/
