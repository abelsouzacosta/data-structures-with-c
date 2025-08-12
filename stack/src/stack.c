#include "../headers/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief initialize the stack
 *
 * top stores the current index of the last element inserted in
 * the stack
 *
 * @param *stack reference to the stack
 */
void initialize_stack(struct Stack *stack) { stack->top = -1; }

bool is_empty(struct Stack *stack) { return stack->top <= 0 ? true : false; }

bool is_full(struct Stack *stack) {
  return stack->top == STACK_MAX_SIZE ? true : false;
}

void push(struct Stack *stack, unsigned int value) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    return;
  }

  // the stack is full
  if (is_full(stack)) {
    fprintf(stderr, "Stack full");
    return;
  }

  // top stores the last element inserted within the array
  stack->elements[stack->top += 1] = value;
  printf("%d pushed into the stack\n", value);
  return;
}

int pop(struct Stack *stack) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    exit(EXIT_FAILURE);
  }

  if (is_empty(stack)) {
    fprintf(stderr, "Stack empty");
    exit(EXIT_FAILURE);
  }

  unsigned int popped = stack->elements[stack->top];
  // shrinks the given array
  stack->top -= 1;
  // return the popped element
  return popped;
}

int peek(struct Stack *stack) {
  if (!stack) {
    fprintf(stderr, "No stack was provided");
    exit(EXIT_FAILURE);
  }

  unsigned int peek = stack->elements[stack->top];

  return peek;
}

