CC = gcc

CFLAGS = -Wall -Wextra

all: TAD_circular_queue

TAD_circular_queue: main.o circular_queue.o
	$(CC) $(CFLAGS) -o TAD_circular_queue main.o circular_queue.o

main.o: main.c circular_queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

circular_queue.o: circular_queue.c circular_queue.h
	$(CC) $(CFLAGS) -c -o circular_queue.o circular_queue.c

clean:
	rm -f TAD_circular_queue main.o circular_queue.o