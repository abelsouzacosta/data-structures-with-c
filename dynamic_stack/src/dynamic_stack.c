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

unsigned int pop(DStack *stack) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    exit(EXIT_FAILURE);
  }

  // if the list is empty then do nothing
  if (is_empty(stack))
    exit(EXIT_FAILURE);

  // stores the item to be removed from the stack (and the list)
  unsigned int popped = stack->elements->head->data;
  // removes the element from the head of the linked list
  delete_from_head(stack->elements);
  // updates the top of the head
  stack->top = stack->elements->head;

  // return the popped element
  return popped;
}

unsigned int peek(DStack *stack) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    exit(EXIT_FAILURE);
  }

  // stores the data of the node at the head
  unsigned int peek = stack->elements->head->data;

  // return the value no need to update the top
  return peek;
}

void print_stack(DStack *stack) {
  if (stack->top != NULL && stack->elements != NULL) {
    Node *current = stack->elements->head;
    while (current != NULL) {
      printf("%u\n", current->data);
      current = current->next;
    }
  }
  return;
}
