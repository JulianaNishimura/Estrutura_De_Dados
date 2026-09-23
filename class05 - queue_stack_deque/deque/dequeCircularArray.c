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

void destroyDeque(Deque* deque) {
    if (deque != NULL) {
        free(deque);
    }
}

int main() {
    Deque* deque = createDeque();

    insertLast(deque, 10);
    insertLast(deque, 20);
    insertFirst(deque, 5);
    insertFirst(deque, 1);
    insertLast(deque, 30);
    printDeque(deque);

    if (!insertLast(deque, 99)) {
        printf("Push failed: Deque full\n");
    }

    int removedItem;
    if (removeFirst(deque, &removedItem)) printf("Pop front: %d\n", removedItem);
    if (removeLast(deque, &removedItem))  printf("Pop back: %d\n", removedItem);
    printDeque(deque);

    if (insertLast(deque, 40)) printf("Push back: 40\n");
    printDeque(deque);

    destroyDeque(deque);
    return 0;
}
