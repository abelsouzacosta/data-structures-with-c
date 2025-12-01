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

LlNode *init_node(uint data) {
  LlNode *new_node = (LlNode *)malloc(sizeof(LlNode));
  if (new_node == NULL) {
    printf("There was an error trying to all9ocate the node");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}
