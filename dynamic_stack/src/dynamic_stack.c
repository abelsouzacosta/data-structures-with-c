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

bool is_empty(DStack *stack) {
  return stack->top == NULL || stack->elements->head == NULL ? true : false;
}

void push(DStack *stack, unsigned int value) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    return;
  }

  // insert an element at the head of the linked list
  insert_at_head(stack->elements, value);
  // the element at the top of the linked list is now the head
  stack->top = stack->elements->head;

  return;
}

