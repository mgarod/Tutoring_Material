# Title: Sample makefile
# Author: Michael Garod
# Date Created: 7/16/15
#	
# A makefile is a script that will execute a series of commends
#	en lieu of having the human do them on the command line.
#
# This makefile will generate an executable called TestSet dependent on OBJS
# In order for it to continue, it will then generate all OBJS, in this case
#	it only has one item to build, TestSet.o, which depends on TestSet.cpp
# These aliases OBJS, CC, DEBUG, CFLAGS, LFLAGS all exist so that when your
#	makefiles become large, you can make changes to all pieces at once by
#	modifying a single alias.
# The formatting for makefiles are very strict. The tabs below each colon
#	are very specific and indicate which instructions to follow.
#
# To build your program, simply enter "make" into the terminal.

############################################################################
# These are the aliases. Think of them as variables. Everywhere you see
#	these names, the interpreter merely copy-pastes their values in place.
EXE = TestSet
OBJS = TestSet.o
SOURCE = TestSet.cpp
CC = g++
DEBUG = -g -pedantic
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(EXE): $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

$(OBJS):
	$(CC) -c $(SOURCE)

# This is an additional instruction that is run by "make clean". The
#	interpreter will only run the commands under "clean:"
clean: $(OBJS) $(EXE)
	rm $(OBJS) $(EXE)
