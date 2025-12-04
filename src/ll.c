#include "../headers/ll.h"
#include <stdio.h>
#include <stdlib.h>

Sll *create_list(void) {
  Sll *list = (Sll *)malloc(sizeof(Sll));
  if (list == NULL) {
    printf("There was an error trying to allocate the list");
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

LlNode *init_node(uint data) {
  LlNode *new_node = (LlNode *)malloc(sizeof(LlNode));
  if (new_node == NULL) {
    printf("There was an error trying to all9ocate the node");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void check_list(Sll *list) {
  if (list == NULL) {
    perror("Probably there was an error trying to allocate the list");
    exit(1);
  }
}

bool is_empty(Sll *list) { return list->head == NULL ? true : false; }

bool is_unary(Sll *list) { return list->head == list->tail ? true : false; }

void insert_at_empty_list(Sll *list, LlNode *node) {
  check_list(list);
  list->head = node;
  list->tail = node;
  return;
}

void insert_at_head(Sll *list, uint data) {
  check_list(list);
  LlNode *new_node = init_node(data);
  if (is_empty(list)) {
    insert_at_empty_list(list, new_node);
    return;
  }
  new_node->next = list->head;
  list->head = new_node;
  return;
}

void insert_at_tail(Sll *list, uint data) {
  check_list(list);
  LlNode *new_node = init_node(data);
  if (is_empty(list)) {
    insert_at_empty_list(list, new_node);
    return;
  }
  list->tail->next = new_node;
  list->tail = new_node;
  return;
}

void delete_from_unary_list(Sll *list) {
  free(list->head);
  list->head = NULL;
  list->tail = NULL;
  return;
}

void delete_at_head(Sll *list) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  if (is_unary(list)) {
    delete_from_unary_list(list);
    return;
  }
  LlNode *node_to_delete = list->head;
  list->head = node_to_delete->next;
  free(node_to_delete);
  return;
}

void delete_at_tail(Sll *list) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  if (is_unary(list)) {
    delete_from_unary_list(list);
    return;
  }
  LlNode *runner = list->head;
  while (runner != NULL && runner->next != list->tail) {
    runner = runner->next;
  }
  LlNode *node_to_delete = runner->next;
  runner->next = NULL;
  list->tail = runner;
  free(node_to_delete);
  return;
}

void reverse(Sll *list) {
  check_list(list);
  if (is_empty(list) || is_unary(list)) {
    return;
  }
  LlNode *runner = list->head;
  LlNode *old_head = list->head;
  LlNode *previous = NULL;
  while (runner != NULL) {
    LlNode *next = runner->next; // stores the next value
    runner->next = previous;
    previous = runner;
    runner = next; // moves forward in the list
  }
  // updates the head and the tail
  list->head = previous;
  list->tail = old_head;
  return;
}

void reverse_first(Sll *list, uint n) {
  check_list(list);
  if (is_empty(list) || is_unary(list) || n == 0) {
    return;
  }
  LlNode *runner = list->head;
  LlNode *blockTail = list->head;
  LlNode *previous = NULL;
  LlNode *next = NULL;
  uint positions = 0; // accumulator for positions
  while (runner != NULL && positions < n) {
    ++positions;
    next = runner->next;
    runner->next = previous;
    previous = runner;
    runner = next;
  }
  // partially ordered list
  if (next != NULL) {
    blockTail->next = next;
  }
  list->head = previous;
  return;
}

void swap(Sll *list) {
  check_list(list);
  if (is_empty(list) || is_unary(list)) {
    return;
  }
  LlNode *first_element = list->head;
  LlNode *second_element = list->head->next;

  // updates the references
  first_element->next = second_element->next;
  second_element->next = first_element;
  list->head = second_element;
  return;
}

void remove_duplicates(Sll *list) {
  check_list(list);
  if (is_empty(list) || is_unary(list)) {
    return;
  }
  // two pointer technique
  LlNode *current = list->head;
  while (current != NULL) {
    LlNode *runner = current;
    while (runner->next != NULL) {
      if (current->data == runner->next->data) {
        LlNode *node_to_delete = runner->next;
        // edge case if the duplicated node is the last node
        // of the list
        if (node_to_delete == list->tail) {
          list->tail = runner;
        }
        runner->next = node_to_delete->next;
        free(node_to_delete);
      } else {
        runner = runner->next;
      }
    }
    current = current->next;
  }
  return;
}

void print_list(Sll *list) {
  check_list(list);
  if (is_empty(list)) {
    printf("[]");
  }
  LlNode *runner = list->head;
  printf("[");
  while (runner != NULL) {
    if (runner == list->tail) {
      printf("%u", runner->data);
    } else
      printf("%u -> ", runner->data);
    runner = runner->next;
  }
  printf("]\n");
  return;
}
