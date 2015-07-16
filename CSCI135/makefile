# Title: Sample makefile
# Author: Michael Garod
# Date Created: 7/16/15
#	
# A makefile is a script that will execute a series of commends
#	en lieu of having the human do them on the command line.
# 
# This makefile will generate an executable called EXE dependent on OBJS
# In order for it to continue, it will then generate OBJS, and in this case
#	it only has one item to build, TestSet.o, which depends on SOURCE.
# These aliases OBJS, CC, DEBUG, CFLAGS, LFLAGS all exist so that when your
#	makefiles become large, you can make changes to all pieces at once by
#	modifying a single alias at the top.
# The formatting for makefiles is very strict. The tabs below each colon for
#	example, are very specific and indicate which instructions to follow.
# 
# To build the program, simply enter "make" into the terminal.
# 
# To test this makefile, you can get the source files here:
#	https://github.com/mgarod/MathSet

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
