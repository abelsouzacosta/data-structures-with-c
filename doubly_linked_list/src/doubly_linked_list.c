#include "../headers/doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(unsigned int data) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    perror("Error allocating memory to the node");
    exit(EXIT_FAILURE);
  }
  new_node->previous = NULL;
  new_node->next = NULL;
  new_node->data = data;

  return new_node;
}

