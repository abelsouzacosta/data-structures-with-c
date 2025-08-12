#include "stack/headers/stack.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Stack stack;
  initialize_stack(&stack);

  push(&stack, 1);
  push(&stack, 30);
  push(&stack, 23);
  push(&stack, 14);

  print_stack(&stack);

  printf("The element at the top is: %u\n", peek(&stack));

  printf("Popping %u", peek(&stack));

  pop(&stack);

  print_stack(&stack);

  return 0;
}
