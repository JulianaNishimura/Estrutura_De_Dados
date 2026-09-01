CC = gcc
CFLAGS = -Wall -Wextra

all: 

TAD_Ordered_List: main.o orderedList.o
	$(CC) $(CFLAGS) -o TAD_Ordered_List main.o orderedList.o

main.o: main.c orderedList.h
	$(CC) $(CFLAGS) -c -o main.o main.c

funcoes.o: orderedList.c orderedList.h
	$(CC) $(CFLAGS) -c -o orderedList.o orderedList.c

clean:
	rm -f TAD_Ordered_List main.o list.o
