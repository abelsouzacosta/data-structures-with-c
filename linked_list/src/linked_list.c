#include "../headers/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(unsigned int data) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    perror("Was not possible to allocate memory to the node");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

LinkedList *init_list(void) {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (list == NULL) {
    perror("Was not possible to allocate memory to the list");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->tail = NULL;

  return list;
}

