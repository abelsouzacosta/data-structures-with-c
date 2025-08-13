#ifndef DYNAMIC_STACK
#define DYNAMIC_STACK

#include "../../linked_list/headers/linked_list.h"
#include <stdbool.h>

typedef struct DStack {
  Node *top;
  LinkedList *elements;
} DStack;

DStack initialize_stack(void);

void push(DStack *stack, unsigned int value);

unsigned int pop(DStack *stack);

#endif // !DYNAMIC_STACK
