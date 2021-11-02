# compiler flags.  -g for debug, -O3 for optimization
CFLAGS=-g -O3

# first target built by default

all: uimain
# file dependencies

tokenizer.o: tokenizer.h
history.o: history.h

# compiles the tokenizer

uimain: tokenizer.o history.o uimain.o
	cc -o $@ $^ $(CFLAGS)

# deltes the files generated from the compilation

clean:
	rm -f *.o *.c~ *.*# *.h.gch *.out str root exec *: id next tester.c Makefile~ tokens uimain
run: uimain
	./uimain.c
