#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    struct stack *stack = (struct stack *) malloc(sizeof(struct stack));
    stack_initialize(stack, 1);
    stack_push(stack, 1);
    int data = stack_pop(stack);
    printf("%d\n",data);
    stack_destroy(stack);
    free(stack);
}