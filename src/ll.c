#include "../headers/ll.h"
#include <stdio.h>
#include <stdlib.h>

Sll *create_list(void) {
  Sll *list = (Sll *)malloc(sizeof(Sll));
  if (list == NULL) {
    printf("There was an error trying to allocate the list");
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

