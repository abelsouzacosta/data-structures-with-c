#include "../headers/dynamic_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

DStack *initialize_stack(void) {
  DStack *stack = malloc(sizeof(DStack));
  if (!stack) {
    perror("Was not possible to allocate space for the stack");
    exit(EXIT_FAILURE);
  }
  LinkedList *elements = init_list();
  if (!elements) {
    perror("Was not possible to allocate space for the elements of the stack");
    exit(EXIT_FAILURE);
  }
  stack->elements = elements;
  stack->top = NULL;

  return stack;
}

