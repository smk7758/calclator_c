OBJECTS = calclator.c node.c parse.c eval.c 
CC = gcc

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o calclator.out -lm

install: all
	./calclator.out
	./calclator.out test

clean:
	-rm -i calclator.out

