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

void check_list(DoublyLinkedList *list) {
  if (list == NULL) {
    perror("Probably there was an error trying to allocate the list");
    exit(1);
  }
}

Node *init_node(uint data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("There was an error trying to create a node");
    return NULL;
  }
  new_node->previous = NULL;
  new_node->next = NULL;
  new_node->data = data;
  return new_node;
}
