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

void insert_at_head(LinkedList *list, unsigned int data) {
  Node *node = create_node(data);

  // check if the list is not empty
  if (list->head != NULL) {
    Node *old_head = list->head; // aux to receive the previous head
    list->head = node;
    node->next = old_head;
  } else { // the tail stills the same for every insertion at the head
    list->head = node;
    list->tail = node;
  }
}

