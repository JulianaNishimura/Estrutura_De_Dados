/*
Advantages
    Flexible insertion and removal: Elements can be added and removed from both
    the beginning and the end of the deque.
    Efficient operations: Insertion and removal at both ends can be performed
    in O(1) time.
    Versatile structure: A deque can be used as both a queue and a stack,
    depending on how the operations are performed.

Disadvantages
    More complex implementation: Managing both ends of the structure requires
    more control than a simple queue or stack.
    Fixed size: In a static deque, the maximum number of elements must be defined
    when the deque is allocated.
    No direct access: Elements should be accessed through the operations at the
    beginning or the end of the deque.

When to use
    When elements need to be added or removed from both ends, especially in
    situations such as task scheduling, sliding window problems, and
    implementing both stack and queue behavior.
*/
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
    return deque;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int isEmpty(Deque* deque) {
    return (deque == NULL || deque->size == 0);
}

int insertFirst(Deque* deque, int value) {
    if (deque == NULL) return 0;
    Node* newNode = createNode(value);
    if (newNode == NULL) return 0;
    
    if (isEmpty(deque)) {
        deque->head = deque->tail = newNode;
    } else {
        newNode->next = deque->head;
        deque->head->prev = newNode;
        deque->head = newNode;
    }
    deque->size++;
    return 1;
}

int insertLast(Deque* deque, int value) {
    if (deque == NULL) return 0;
    Node* newNode = createNode(value);
    if (newNode == NULL) return 0;
    
    if (isEmpty(deque)) {
        deque->head = deque->tail = newNode;
    } else {
        newNode->prev = deque->tail;
        deque->tail->next = newNode;
        deque->tail = newNode;
    }
    deque->size++;
    return 1;
}

int removeFirst(Deque* deque, int *value) {
    if (isEmpty(deque)) {
        return 0;
    }
    
    Node* temp = deque->head;
    *value = temp->data;
    deque->head = deque->head->next;
    
    if (deque->head == NULL) {
        deque->tail = NULL;
    } else {
        deque->head->prev = NULL;
    }
    free(temp);
    deque->size--;
    return 1;
}

int removeLast(Deque* deque, int *value) {
    if (isEmpty(deque)) {
        return 0;
    }
    
    Node* temp = deque->tail;
    *value = temp->data;
    deque->tail = deque->tail->prev;
    
    if (deque->tail == NULL) {
        deque->head = NULL;
    } else {
        deque->tail->next = NULL;
    }
    
    free(temp);
    deque->size--;
    return 1;
}

void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        return;
    }

    Node* current = deque->head;

    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void destroyDeque(Deque* deque) {
    if (deque == NULL) return;

    int x;
    while (!isEmpty(deque)) {
        removeFirst(deque,&x);
        printf("\nRemoved %d",x);
    }

    free(deque);
}
