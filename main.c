#include "arrays/headers/int_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  unsigned int number_of_elements = 5;
  int *numbers = malloc(sizeof(int) * number_of_elements);
  if (numbers == NULL) {
    perror("Was not possible to allocate the array");
    return -1;
  }
  int original[] = {11, 23, 44, 10, 54};
  memcpy(numbers, original, sizeof(int) * number_of_elements);

  print_array(numbers, number_of_elements);

  int *new_array = pop(numbers, number_of_elements, 10);

  print_array(new_array, 4);

  return 0;
}
