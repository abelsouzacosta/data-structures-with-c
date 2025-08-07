#include "recursivity/headers/recursive.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned int user_input;

  printf("Enter a number: ");
  scanf("%d", &user_input);

  countdown(user_input);

  unsigned int factorial_result = factorial(user_input);

  printf("\nThe result of the factorial is: %d", factorial_result);

  return 0;
}
