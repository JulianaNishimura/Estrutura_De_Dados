#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Deque {
    int data[MAX];
    int head;
    int tail;
    int size;
} Deque;

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->head = -1;
    deque->tail = 0;
    deque->size = 0;
    return deque;
}

int isEmpty(Deque* deque) {
    return (deque == NULL || deque->size == 0);
}

int isFull(Deque* deque) {
    return (deque != NULL && deque->size == MAX);
}

int insertFirst(Deque* deque, int value) {
    if (deque == NULL || isFull(deque)) return 0;
    
    if (deque->head == -1) {
        deque->head = 0;
        deque->tail = 0;
    } else {
        deque->head = (deque->head - 1 + MAX) % MAX;
    }

    deque->data[deque->head] = value;
    deque->size++;
    return 1;
}

int insertLast(Deque* deque, int value) {
    if (deque == NULL || isFull(deque)) return 0;
    
    if (deque->head == -1) {
        deque->head = 0;
        deque->tail = 0;
    } else {
        deque->tail = (deque->tail + 1) % MAX;
    }

    deque->data[deque->tail] = value;
    deque->size++;
    return 1;
}

int removeFirst(Deque* deque, int* removedValue) {
    if (isEmpty(deque) || removedValue == NULL) return 0;
    
    *removedValue = deque->data[deque->head];
    if (deque->head == deque->tail) {
        deque->head = -1;
        deque->tail = 0;
    } else {
        deque->head = (deque->head + 1) % MAX;
    }

    deque->size--;
    return 1;
}

int removeLast(Deque* deque, int* removedValue) {
    if (isEmpty(deque) || removedValue == NULL) return 0;
    
    *removedValue = deque->data[deque->tail];
    if (deque->head == deque->tail) {
        deque->head = -1;
        deque->tail = 0;
    } else {
        deque->tail = (deque->tail - 1 + MAX) % MAX;
    }

    deque->size--;
    return 1;
}

void printDeque(Deque* deque) {
    if (isEmpty(deque)) return;
    
    printf("Deque: ");
    int index = deque->head;
    int i;
    for (i = 0; i < deque->size; i++) {
        printf("%d ", deque->data[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

void freeDeque(Deque* deque) {
    if (deque != NULL) {
        free(deque);
    }
}

int main() {
    Deque* myDeque = createDeque();

    insertLast(myDeque, 10);
    insertLast(myDeque, 20);
    insertFirst(myDeque, 5);
    insertFirst(myDeque, 1);
    insertLast(myDeque, 30);
    printDeque(myDeque);

    if (!insertLast(myDeque, 99)) {
        printf("Push failed: Deque full\n");
    }

    int removedItem;
    if (removeFirst(myDeque, &removedItem)) printf("Pop front: %d\n", removedItem);
    if (removeLast(myDeque, &removedItem))  printf("Pop back: %d\n", removedItem);
    printDeque(myDeque);

    if (insertLast(myDeque, 40)) printf("Push back: 40\n");
    printDeque(myDeque);

    freeDeque(myDeque);
    return 0;
}
