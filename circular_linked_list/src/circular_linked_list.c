#include "../headers/circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(unsigned int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Error allocating memory to the node");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

