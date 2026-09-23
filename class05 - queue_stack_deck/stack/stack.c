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
