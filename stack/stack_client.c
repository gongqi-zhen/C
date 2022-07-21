#include <stdio.h>
#include "stack.h"

int main(void) {
    struct stack stack;
    stack_initialize(&stack, 1);
    stack_push(&stack, 1);
    int data = stack_pop(&stack);
    printf("%d\n",data);
    stack_destroy(&stack);
}