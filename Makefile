#
# Makefile
# Florian Leprince, 2014-10-28 23:41
#

EXE=gaia
SRCDIR=src
BINDIR=bin
CC=g++
CFLAGS=-Wall -ansi -pedantic -g -std=gnu++0x
LIBS=$(shell sdl-config --cflags --libs) -lGL -lGLU
SRCPATH=$(wildcard $(SRCDIR)/*.cpp)
SRCFILE=$(patsubst $(SRCDIR)/%,%,$(SRCPATH))
OBJFILE=$(SRCFILE:.cpp=.o)
OBJPATH=$(addprefix $(BINDIR)/,$(OBJFILE))

all: $(EXE)
	@echo "Compilation achieved"

$(EXE): $(OBJPATH)
	@echo "Building $@"
	$(CC) -o $(EXE) $(OBJPATH) $(LIBS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(BINDIR)/
	@echo "Build $< => $@"
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINDIR)/:
	@mkdir bin

.PHONY: clean cleanall

clean:
	@rm -rf $(BINDIR)/

cleanall: clean
	@rm -rf $(EXE)

# vim:ft=make
#
