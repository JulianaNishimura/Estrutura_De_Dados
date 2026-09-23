CC = gcc

CFLAGS = -Wall -Wextra

all: TAD_stack

TAD_stack: main.o stack.o
	$(CC) $(CFLAGS) -o TAD_stack main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
	rm -f TAD_stack main.o stack.o