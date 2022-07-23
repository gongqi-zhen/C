struct stack; // forward declaration

struct stack *stack_create(int initialCapacity);
void stack_destroy(struct stack *stack);

void stack_push(struct stack *stack, int data);
int stack_pop(struct stack *stack);
int stack_peek(struct stack *stack);
int stack_isEmpty(struct stack *stack);