#
# Makefile
# Florian Leprince, 2014-10-28 23:41
#

EXE=gaia
SRCDIR=src
BINDIR=bin
CC=g++
CFLAGS=-Wall -ansi -pedantic -g
SRCPATH=$(wildcard $(SRCDIR)/*.cpp)
SRCFILE=$(patsubst $(SRCDIR)/%,%,$(SRCPATH))
OBJFILE=$(SRCFILE:.cpp=.o)
OBJPATH=$(addprefix $(BINDIR)/,$(OBJFILE))

all: $(EXE)
	@echo "Compilation achieved"

$(EXE): $(OBJPATH)
	@$(CC) -o $(EXE) $(OBJPATH)
	@echo "Building "

$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(BINDIR)/
	@echo "Build $< => $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

$(BINDIR)/:
	@mkdir bin

.PHONY: clean cleanall

clean:
	@rm -rf $(BINDIR)/

cleanall: clean
	@rm -rf $(EXE)

# vim:ft=make
#
