#ifndef STACK
#define STACK

#define STACK_MAX_SIZE 100

typedef struct Stack {
  unsigned int top;
  unsigned int elements[STACK_MAX_SIZE];
} Stack;

void initialize_stack(struct Stack *stack);

#endif // !STACK
