#include "arrays/int_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *numbers = create_int_array_with_size(5);

  printf("The old array: ");
  for (int counter = 0; counter < 5; counter += 1) {
    numbers[counter] = counter;
    printf("%d\n", numbers[counter]);
  }

  numbers = remove_element_at_position(2, 5, numbers);

  printf("The new array: ");
  for (int counter = 0; counter <= 5; counter += 1) {
    printf("%d\n", numbers[counter]);
  }

  free(numbers);
}
