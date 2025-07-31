#include "../headers/int_array.h"
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

int *remove_element_at_position(int position, int size, int *array) {
  if (!position) {
    fprintf(stderr, "Position was not provided");
    return NULL;
  }
  if (!size) {
    fprintf(stderr, "The size of the array was not provided");
    return NULL;
  }
  if (!array) {
    fprintf(stderr, "Array was not provided");
    return NULL;
  }
  // the element removed
  int element_removed = array[position];
  // calculates the size for the new array
  int new_array_size = size - 1;
  // creates a new array
  int *new_array = create_int_array_with_size(new_array_size);
  // shift the elements in the original array to the left
  for (int counter = position; counter < size - 1; counter += 1) {
    array[counter] = array[counter + 1];
  }
  // populates the new array with the contents of the old one
  for (int counter = 0; counter < new_array_size; counter += 1) {
    new_array[counter] = array[counter];
  }
  free(array);
  return new_array;
}

int *insert_first_position(int element, int size, int *array) {
  if (!element) {
    fprintf(stderr, "The element to be inserted was not provided");
    return NULL;
  }
  if (!size) {
    fprintf(stderr, "The size of the array was not provided");
    return NULL;
  }
  if (!array) {
    fprintf(stderr, "No array was provided");
    return NULL;
  }
  // reallocates the array
  int new_array_size = size + 1;
  int *new_array = realloc(array, sizeof(int) * new_array_size);
  if (new_array == NULL) {
    fprintf(stderr, "Was not possible to realloc the array");
    return NULL;
  }
  array = new_array;
  for (int counter = new_array_size; counter > 0; counter -= 1) {
    array[counter] = array[counter - 1];
  }
  array[0] = element;
  return array;
}

int *insert_at_last_position(int *array, int size, int element) {
  if (!array) {
    fprintf(stderr, "No array was provided");
    return NULL;
  }
  if (!size) {
    fprintf(stderr, "The size of the array was not provided");
    return NULL;
  }
  if (!element) {
    fprintf(stderr, "The element to be inserted was not provided");
    return NULL;
  }
  // reallocates the array
  int new_array_size = size + 1;
  int *new_array = realloc(array, sizeof(int) * new_array_size);
  if (new_array == NULL) {
    perror("Was not possible to reallocate the array given");
    return NULL;
  }
  printf("here");
  array = new_array;
  // the last position of the new realloced array
  // will be the size of the original array
  int last_position = size;
  array[last_position] = element;
  return array;
}

int _binary_search(int *array, int size, int element) {
  int right = size - 1;
  int left = 0;
  while (left <= right) {
    int middle = (left + right) / 2;

    if (array[middle] == element)
      return middle;
    if (array[middle] < element) {
      // element at the rightmost part of the section
      left = middle + 1;
    }
    if (array[middle] > element) {
      // element at the leftmost part of the section
      right = middle - 1;
    }
  }
  return -1;
}
}
