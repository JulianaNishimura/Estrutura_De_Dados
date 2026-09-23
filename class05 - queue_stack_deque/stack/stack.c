/*
Advantages
    Simple implementation: The stack follows a straightforward LIFO (Last In, First Out) structure,
    making it easy to implement and understand.
    Efficient insertion and removal: Adding and removing elements from the top of the stack
    can be performed in O(1) time.

Disadvantages
    Fixed size: In a static stack, the maximum number of elements must be defined
    when the stack is allocated.
    Limited access: Elements can only be accessed through the top of the stack,
    following the LIFO order.
    Limited space usage: When the stack is full, new elements cannot be added
    until an element is removed.

When to use
    When elements need to be processed in reverse order of insertion, especially
    in situations such as function calls, undo operations, expression evaluation,
    and backtracking.
*/
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

t_stack* create_stack(int max) {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->max = max;
    stack->top_index = -1;
    stack->items = malloc(sizeof(int) * max);
    return stack;
}

int is_empty(t_stack* stack) {
    return stack->top_index < 0;
}

int is_full(t_stack* stack) {
    return stack->top_index >= stack->max - 1;
}

int push(t_stack* stack, int x) {
    if (is_full(stack)) {
        return 0;
    }
    stack->top_index++;
    stack->items[stack->top_index] = x;
    return 1;
}

int pop(t_stack* stack, int *x) {
    if (is_empty(stack)) {
        return 0;
    }
    *x = stack->items[stack->top_index];
    stack->top_index--;
    return 1;
}

int top(t_stack* stack, int *x) {
    if (is_empty(stack)) {
        return 0;
    }
    *x = stack->items[stack->top_index];
    return 1;
}

void clear(t_stack* stack) {
    stack->top_index = -1;
}

int size(t_stack* stack) {
    return stack->top_index + 1;
}

void print(t_stack* stack) {
    if(is_empty(stack)) return;
    int i = stack->top_index;

    printf("\nStack:\n");
    while(i >= 0){
        printf("%d ",stack->items[i]);
        i--;
    };
}

void destroy(t_stack* stack) {
    free(stack->items);
    free(stack);
}
