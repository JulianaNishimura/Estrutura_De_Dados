#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]) {

    t_stack *stack;

    stack = create_stack(5);

    printf("empty: %d\n", is_empty(stack));
    printf("size: %d\n", size(stack));

    printf("\npush 3: %d\n", push(stack, 3));
    printf("push 8: %d\n", push(stack, 8));
    printf("push 9: %d\n", push(stack, 9));
    printf("push 4: %d\n", push(stack, 4));

    print(stack);

    printf("\nsize: %d\n", size(stack));

    int x;

    printf("\npop: %d\n", pop(stack, &x));
    printf("removed: %d\n", x);

    print(stack);

    printf("\ntop: %d\n", top(stack, &x));
    printf("top value: %d\n", x);

    printf("\npush 10: %d\n", push(stack, 10));
    printf("push 20: %d\n", push(stack, 20));

    print(stack);

    printf("\npush 30: %d\n", push(stack, 30));

    printf("\nclearing stack...\n");
    clear(stack);

    printf("empty after clear: %d\n", is_empty(stack));
    printf("size after clear: %d\n", size(stack));

    printf("\npop from empty stack: %d\n", pop(stack, &x));
    printf("top from empty stack: %d\n", top(stack, &x));

    destroy(stack);

    return 0;
}