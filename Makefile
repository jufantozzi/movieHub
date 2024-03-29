# Project name
NAME=trabGrafos


# Directories
INCDIR=include
LIBDIR=lib
BLDDIR=bin
SRCDIR=source
OBJDIR=$(BLDDIR)/obj

# Can use any debbuger (like gdb) or overlay (like valgrind) (though gdb is an overlay too)
DEBUGGER=
DBGFLAGS=-v --leak-check=full --show-leak-kinds=all --read-var-info=yes --track-origins=yes


# This will search for 'anything' terminating in .c inside SRCDIR and set an object rule for each of them (make *.o)
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(foreach file, $(SRC), $(file:$(SRCDIR)/%.c=$(OBJDIR)/%.o))

# Find all .h dependencies
DEPS=$(wildcard $(INCDIR)/*.h)

# Finally something easy to read!
CC=gcc
CFLAGS=-g -Wall -I./$(INCDIR)
# -O3 -Wall -Wextra -I./$(INCDIR)

# Library links (example: -lm for math lib)
LIBS=-lm

# if you run make [target] debug=____ where ____ is anything (even an empty string will do)
ifdef debug
	CFLAGS+= -g
	DEBUGGER=valgrind $(DBGFLAGS) 
endif

all: main

# Compile directives
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@echo Building $*
	@$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	@echo Linking object files
	@$(CC) -o $(BLDDIR)/$(NAME) $^ $(CFLAGS) $(LIBS)


# Run directives
run:
	$(DEBUGGER) ./$(BLDDIR)/$(NAME)

go: main run


# Utility directives
clean:

zip: clean
	@echo Compressing files...
	@zip -j $(NAME).zip source/*.c include/*.h make/Makefile
	@echo Done.
