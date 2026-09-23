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

Node* createNode(int value);
Deque* createDeque();
int isEmpty(Deque* dq);
int insertFirst(Deque* dq, int value); 
int insertLast(Deque* dq, int value);  
int removeFirst(Deque* dq, int *value);             
int removeLast(Deque* dq, int *value);              
void printDeque(Deque* dq);             
void destroyDeque(Deque* dq);

#endif 
