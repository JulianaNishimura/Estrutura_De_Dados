CC = gcc
CFLAGS = -Wall - Wextra

all: main_program

main_program: main.o stack.o
	$(CC) $(FLAGS) -o main_program main.o stack.o

main.o: main.c stack.h
	$(CC) $(FLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(FLAGS) -c -o stack.o stack.c

clear:
	rm -f main_program *.o