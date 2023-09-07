CC=gcc
CFLAGS=-O3 -g -march=native
LDFLAGS=-lm
SRCDIR=./src
EXENAME=acos-approx
BUILDDIR=./build
SRCS := $(shell find $(SRCDIR) -name '*.c')
OBJS := $(subst $(SRCDIR),$(BUILDDIR),$(SRCS:%.c=%.o))

.PHONY : clean clean-bak

all : $(BUILDDIR) $(BUILDDIR)/$(EXENAME)

vars:
	@echo "CC=$(CC)"
	@echo "CFLAGS=$(CFLAGS)"
	@echo "LDFLAGS=$(LDFLAGS)"
	@echo "EXENAME=$(EXENAME)"
	@echo "SRCDIR=$(SRCDIR)"
	@echo "BUILDDIR=$(BUILDDIR)"
	@echo "SRCS=$(SRCS)"
	@echo "OBJS=$(OBJS)"

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXENAME): $(OBJS)
	$(CC) $+ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: clean-bak clean-build

clean-bak:
	@find . -name '*~' | xargs rm -f

clean-build:
	@rm -rf $(BUILDDIR)
