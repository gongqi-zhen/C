struct stack {
    int *elements;
    int capacity;
    int size;
};

void stack_initialize(struct stack *stack, int initialCapacity);
void stack_destroy(struct stack *stack);
void stack_push(struct stack *stack, int data);
int stack_pop(struct stack *stack);