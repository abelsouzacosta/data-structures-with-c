#include "arrays/headers/int_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int number_of_elements = 5;
  int *numbers = malloc(sizeof(int) * number_of_elements);

  for (int counter = 0; counter < number_of_elements; counter += 1) {
    numbers[counter] = (rand() % 100) + 1;
  }

  print_array(numbers, number_of_elements);

  printf("\nThe lowest number in the array given is: %d",
         get_lowest_from_array(numbers, number_of_elements));

  return 0;
}
