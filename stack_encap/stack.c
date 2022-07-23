#include <stdio.h>
#include <string.h>
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