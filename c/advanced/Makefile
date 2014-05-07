#SPECIFIED_SRC_FILE  = $(foreach d,$(SPECIFIED_SRC_DIRS),$(wildcard $(addprefix $(d)/*,*.c)))
#CC = gcc


#all:
#	$(CC) -o .out lelemon.c -Wall
#SRCS=$(wildcard *.c)
#OBJS=(SRCS:.c=.o)
#all: $(OBJS)

CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -Isrc -rdynamic -O2 -fomit-frame-pointer
#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst %.c, %.out, $(wildcard *.c))

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
%.out: %.c Makefile
	    $(CC) $(CFLAGS) $< -o $@ 
