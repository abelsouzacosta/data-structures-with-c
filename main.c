#include "dynamic_stack/headers/dynamic_stack.h"

int main(int argc, char *argv[]) {
  DStack *stack = initialize_stack();
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 6);

  print_stack(stack);
}
