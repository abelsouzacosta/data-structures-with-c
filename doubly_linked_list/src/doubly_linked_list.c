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

DoublyLinkedList *init_list(void) {
  DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

  if (list == NULL) {
    perror("Error allocating memory to the list");
    exit(EXIT_FAILURE);
  }
  // initializing list references
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void insert_at_head(DoublyLinkedList *list, unsigned int data) {
  if (!list) {
    perror("No list provided");
    exit(EXIT_FAILURE);
  }

  // creates a new node
  Node *new_node = create_node(data);

  if (list->head == NULL) { // list is empty
    list->head = new_node;
    list->tail = new_node;
    return;
  }

  // list is not empty
  Node *old_head = list->head;
  new_node->next = old_head;
  list->head = new_node;
  return;
}

void insert_at_tail(DoublyLinkedList *list, unsigned int data) {
  if (!list) {
    perror("No list provided");
    exit(EXIT_FAILURE);
  }

  Node *new_node = create_node(data);

  // list is empty
  if (list->head == NULL) {
    insert_at_head(list, data);
  }
  Node *old_tail = list->tail;
  new_node->previous = old_tail;
  old_tail->next = new_node;
  list->tail = new_node;
}

