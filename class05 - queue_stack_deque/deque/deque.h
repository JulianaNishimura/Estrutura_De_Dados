#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>
#include <limits.h>

#define DEQUE_EMPTY_ERROR INT_MIN

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* head;
    Node* tail;
    int size;
} Deque;

Node* createNode(int);
Deque* createDeque();
int isEmpty(Deque*);
int insertFirst(Deque*, int); 
int insertLast(Deque*, int);  
int removeFirst(Deque*, int*);             
int removeLast(Deque*, int*);              
void printDeque(Deque*);             
void destroyDeque(Deque*);

#endif 
