#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void stack_initialize(struct stack *stack, int initialCapacity) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return;
    }
    if (initialCapacity <= 0) {
        assert(0 && "Illegal initial capacity");
        return;
    }
    stack->elements = (int *) malloc(initialCapacity * sizeof(int));
    stack->capacity = initialCapacity;
    stack->size = 0;
}

void stack_destroy(struct stack *stack) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return;
    }
    free(stack->elements);
}

void stack_push(struct stack *stack, int data) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return;
    }
    if (stack->capacity == stack->size) {
        int newCapacity = stack->capacity * 2 + 1;
        int *newElements = (int *) malloc(newCapacity * sizeof(int));
        memmove(newElements, stack->elements, sizeof(int) * stack->size);
        free(stack->elements);
        stack->elements = newElements;
        stack->capacity = newCapacity;
    }
    stack->elements[stack->size++] = data;
}

int stack_pop(struct stack *stack) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return 0;
    }
    if (stack->size == 0) {
        assert(0 && "Empty stack");
        return 0;
    }
    return stack->elements[--stack->size];
}