CC = gcc

CFLAGS = -Wall -Wextra

all: TAD_deque

TAD_deque: main.o deque.o
	$(CC) $(CFLAGS) -o TAD_deque main.o deque.o

main.o: main.c deque.h
	$(CC) $(CFLAGS) -c -o main.o main.c

deque.o: deque.c deque.h
	$(CC) $(CFLAGS) -c -o deque.o deque.c

clean:
	rm -f TAD_deque main.o deque.o