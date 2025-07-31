#include "arrays/headers/int_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *numbers = create_int_array_with_size(5);

  for (int counter = 0; counter < 5; counter += 1) {
    numbers[counter] = counter;
    printf("%d ", numbers[counter]);
  }

  printf("\n---\n");

  numbers = remove_element_at_position(2, 5, numbers);
  numbers = insert_first_position(15, 4, numbers);

  printf("[");
  for (int counter = 0; counter < 5; counter += 1) {
    if (counter == 4)
      printf("%d", numbers[counter]);
    else
      printf("%d, ", numbers[counter]);
  }
  printf("]");

  free(numbers);
}
