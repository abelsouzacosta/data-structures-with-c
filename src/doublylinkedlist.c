#include "../headers/doublylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyLinkedList *create_list() {
  DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
  if (list == NULL) {
    printf("There was an error trying to allocate the list");
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

