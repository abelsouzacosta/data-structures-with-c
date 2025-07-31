#include "arrays/headers/int_array.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5000000

int main(int argc, char *argv[]) {
  int *numbers = create_int_array_with_size(SIZE);

  for (int counter = 0; counter < SIZE; counter += 1) {
    int number = (counter * 2) + 1;
    numbers[counter] = number;
  }

  int term;
  printf("Type a number ot look for: ");
  scanf("%d", &term);

  int position = binary_search(numbers, SIZE, term);

  if (!position)
    printf("The number is not within the array");
  else
    printf("The number %d is at the position %d\n", term, position);

  printf("%d", numbers[position]);

  free(numbers);
}
