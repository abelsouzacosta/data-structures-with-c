#include "../arrays/int_array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_int_array_with_size(int size) {
  if (size <= 0) {
    fprintf(stderr, "Invalid size provided for array");
    return NULL;
  }
  int *array = malloc(sizeof(int) * size);
  if (array == NULL) {
    perror("Was not possible to allocate the array");
    return NULL;
  }
  memset(array, 0, sizeof(int) * size);
  return array;
}

