#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "stackImpl.h"

struct stack *stack_create(int initialCapacity) {
    if (initialCapacity <= 0) {
        assert(0 && "Illegal initial capacity");
        return NULL;
    }

    struct stack *stack = (struct stack *) malloc(sizeof(struct stack));

    stack->elements = (int *) malloc(initialCapacity * sizeof(int));
    stack->capacity = initialCapacity;
    stack->size = 0;
    return stack;
}

void stack_destroy(struct stack *stack) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return;
    }

    free(stack->elements);
    free(stack);
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

int stack_peek(struct stack *stack) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return 0;
    }
    if (stack->size == 0) {
        assert(0 && "Empty stack");
        return 0;
    }
    return stack->elements[stack->size];
}

int stack_isEmpty(struct stack *stack) {
    if (stack == NULL) {
        assert(0 && "Illegal stack pointer");
        return 0;
    }
    return 1;
}