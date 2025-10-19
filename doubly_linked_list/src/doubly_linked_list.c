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

bool is_list_empty(DoublyLinkedList *list) { return list->head == NULL; }

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
  // updates the previous reference to the node at the head now
  old_head->previous = new_node;
  list->head = new_node;
  return;
}

void insert_at_tail(DoublyLinkedList *list, unsigned int data) {
  if (!list) {
    perror("No list provided");
    exit(EXIT_FAILURE);
  }

  // list is empty
  if (list->head == NULL) {
    insert_at_head(list, data);
    return;
  }

  Node *new_node = create_node(data);
  Node *old_tail = list->tail;
  new_node->previous = old_tail;
  old_tail->next = new_node;
  list->tail = new_node;
}

void insert_after_element(DoublyLinkedList *list, unsigned int reference,
                          unsigned int data) {
  if (!list) {
    perror("List not provided");
    exit(EXIT_FAILURE);
  }

  if (is_list_empty(list)) {
    insert_at_head(list, data);
    return;
  }

  // reference is the tail of the list
  if (list->tail && list->tail->data == reference) {
    insert_at_tail(list, data);
    return;
  }

  Node *current = list->head;
  while (current != NULL && current->data != reference) {
    current = current->next;
  }

  // check if the current is not NULL
  if (!current) {
    fprintf(stderr, "reference %u not found in the list", reference);
    return;
  }

  Node *new_node = create_node(data);
  new_node->next = current->next;
  new_node->previous = current;
  current->next = new_node;
  // without the line below the 'next' reference will still
  // pointing to the pointer at current
  if (new_node->next != NULL)
    new_node->next->previous = new_node;
  else
    list->tail = new_node;
}

void print_list(DoublyLinkedList *list) {
  if (!list) {
    perror("List not provided");
    exit(EXIT_FAILURE);
  }

  Node *current = list->head;

  // empty list
  if (current == NULL) {
    printf("[]");
  }

  while (current != NULL) {
    printf("%u <-> ", current->data);
    current = current->next;
  }
}
