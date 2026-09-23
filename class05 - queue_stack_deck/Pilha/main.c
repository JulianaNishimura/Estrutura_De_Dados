#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main(int argc, char const *argv[]) {
    t_stack *stack;
    stack = create_stack(10);

    push(stack, 3);
    push(stack, 8);
    push(stack, 9);
    push(stack, 4);

    int x;

    pop(stack, &x);

    printf("%d\n", x);

    destroy(stack);
    return 0;
}
