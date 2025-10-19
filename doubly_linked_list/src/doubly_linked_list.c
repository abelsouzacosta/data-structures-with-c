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

void delete_at_head(DoublyLinkedList *list) {
  if (!list) {
    perror("No list provided");
    exit(EXIT_FAILURE);
  }

  if (is_list_empty(list)) {
    perror("Empty list");
    exit(EXIT_FAILURE);
  }

  Node *old_head = list->head;

  if (list->head->next) { // more than one element in the list
    Node *new_head = list->head->next;
    new_head->previous = NULL;
    list->head = new_head;
    free(old_head);
  } else {
    list->head = NULL;
    list->tail = NULL;
    free(old_head);
  }
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

void delete_at_tail(DoublyLinkedList *list) {
  if (!list) {
    fprintf(stderr, "No list provided");
    return;
  }

  if (is_list_empty(list)) {
    fprintf(stderr, "Empty list");
    return;
  }
  // list has only one element
  if (list->head == list->tail) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }
  // list has more than one element
  Node *old_tail = list->tail;
  list->tail = old_tail->previous;
  list->tail->next = NULL; // updates the next pointer of the tail
  free(old_tail);
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

  printf("[");
  while (current != NULL) {
    printf("%u", current->data);
    if (current->next) {
      printf(" <-> ");
    }
    current = current->next;
  }
  printf("]\n");
}
