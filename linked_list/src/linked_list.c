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

void insert_at_tail(LinkedList *list, unsigned int data) {
  Node *node = create_node(data);

  // if the list is not empty
  if (list->tail != NULL) {
    Node *current_tail = list->tail; // aux to store the current tail
    current_tail->next = node; // update the next pointer of the current tail
    list->tail = node;         // update the tail pointer to the new node
  } else {                     // list is empty
    list->head = node;
    list->tail = node;
  }
}

void insert_after_element(LinkedList *list, unsigned int reference,
                          unsigned int data) {
  Node *new_node = create_node(data);
  if (!list) {
    perror("List was not provided");
    exit(EXIT_FAILURE);
  }

  Node *current = list->head;

  // iterates until the reference
  while (current != NULL && current->data != reference) {
    current = current->next;
  }

  // reference is found
  if (current != NULL && current->data == reference) {
    // stores the next node of the reference
    Node *next_node = current->next;
    // updates the next pointer of the reference
    current->next = new_node;
    // updates the next pointer of the new node to
    // the previous next pointer
    new_node->next = next_node;
  } else {
    insert_at_tail(list, data);
  }
}

void print_list(LinkedList *list) {
  if (!list) {
    fprintf(stderr, "No list was provided to print");
    exit(EXIT_FAILURE);
  }

  Node *current = list->head;

  while (current != NULL) {
    printf("%u -> ", current->data);
    current = current->next;
  }

  // if the list is empty or at the end
  if (current == NULL)
    printf("NULL");
}

int get_tail(LinkedList *list) {
  if (list->tail == NULL) {
    fprintf(stdout, "List empty");
    exit(EXIT_SUCCESS);
  }
  return list->tail->data;
}

int get_head(LinkedList *list) {
  if (list->head == NULL) {
    fprintf(stdout, "List empty");
    exit(EXIT_SUCCESS);
  }
  return list->head->data;
}

void delete_from_head(LinkedList *list) {
  if (!list) {
    fprintf(stderr, "No list was provided");
    exit(EXIT_FAILURE);
  }

  // list is empty
  if (!list->head)
    return;

  // list has only one element
  if (list->head == list->tail) {
    free(list->head);
    list->head = list->tail = NULL;
    return;
  }

  // list is not empty
  // takes the second element from the list
  Node *second_element = list->head->next;
  // takes the current head
  Node *current_head = list->head;
  // delete the current head
  free(current_head);
  // move the pointer of the head to the second element
  list->head = second_element;
}

void delete_from_tail(LinkedList *list) {
  if (!list) {
    fprintf(stderr, "No list was provided");
    exit(EXIT_FAILURE);
  }

  // if the list is empty
  if (!list->head)
    return;

  // in the case that there are only one
  // node within the list
  if (list->head == list->tail) {
    free(list->head);
    list->head = list->tail = NULL;
    return;
  }

  // the list is not empty and there are more than one
  // element within it
  if (list->tail != NULL) {
    Node *current = list->head;
    Node *current_tail = list->tail;
    // goes until tail - 1
    while (current->next != list->tail) {
      current = current->next;
    }
    // removes the reference in the tail - 1 element
    current->next = NULL;
    // deletes the previous tail from memory
    free(current_tail);
  }
}

void delete_element(LinkedList *list, unsigned int reference) {
  if (!list) {
    fprintf(stderr, "No list was provided");
    exit(EXIT_FAILURE);
  }

  // if the list is empty
  if (!list->head)
    return;

  // the node to delete is the head
  if (list->head->data == reference) {
    delete_from_head(list);
    return;
  }

  Node *current = list->head;
  // traverse until before the node containing the reference
  while (current != NULL && current->next != NULL &&
         current->next->data != reference) {
    current = current->next;
  }

  // if the reference is not on the list
  if (current == NULL || current->next == NULL) {
    return;
  }

  // node to delete is the tail
  if (current->next == list->tail) {
    delete_from_tail(list);
    return;
  }

  // found the node
  Node *node_to_delete = current->next;
  // updates the current next pointer to
  // the node to delete next pointer
  current->next = node_to_delete->next;
  // deletes the node from the memory
  free(node_to_delete);
  return;
}

void reverse_list(LinkedList *list) {
  if (!list) {
    fprintf(stderr, "No list was provided");
    return;
  }
  // check if the list is empty
  if (!list->head)
    return;

  // check if there are only one element within the list
  if (list->head == list->tail)
    return;

  Node *previous = NULL;
  Node *current = list->head;
  Node *next = NULL;
  Node *old_head =
      list->head; // keeps track of the old head to update as a the tail later

  while (current != NULL) {
    // stores the next element
    next = current->next;
    // updates the next pointer of the node to its previous position
    current->next = previous;
    // move on
    previous = current;
    current = next;
  }

  list->head = previous;
  list->tail = old_head;

  return;
}
