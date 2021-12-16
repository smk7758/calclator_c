OBJECTS = calclator.c node.c
CC = gcc

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o calclator.out

install: all
	./calclator.out

clean:
	-rm calclator calclator.out
