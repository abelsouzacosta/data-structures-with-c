#include "recursivity/headers/recursive.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned int user_input;

  printf("Enter a number: ");
  scanf("%d", &user_input);

  countdown(user_input);

  return 0;
}
