#include "../headers/recursive.h"
#include <stdio.h>
#include <stdlib.h>

void countdown(unsigned int number) {
  if (number < 0) {
    fprintf(stderr, "An invalid number was provided");
    exit(1);
  }

  // base case
  if (number == 0) {
    printf("0");
    exit(0);
  } else { // recursive case
    printf("%d...", number);
    countdown(number - 1);
  }
}
