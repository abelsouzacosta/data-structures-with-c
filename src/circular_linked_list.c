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

CircularLinkedList *init_list() {
  CircularLinkedList *list =
      (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
  if (list == NULL) {
    fprintf(stderr, "Error allocating memory to the list");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void insert_at_head(CircularLinkedList *list, unsigned int data) {
  Node *new_node = create_node(data);
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    new_node->next = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;
  list->tail->next = list->head;
}

void print_list(CircularLinkedList *list) {
  Node *current = list->head;

  if (current == NULL) {
    printf("[]");
  }

  printf("[");
  do {
    printf("%u ", current->data);
    current = current->next;
  } while (current != NULL && current != list->head);
  printf("]");
}
