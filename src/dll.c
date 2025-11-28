#include "../headers/dll.h"
#include <stdio.h>
#include <stdlib.h>

Dll *create_list() {
  Dll *list = (Dll *)malloc(sizeof(Dll));
  if (list == NULL) {
    printf("There was an error trying to allocate the list");
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void check_list(Dll *list) {
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

bool is_empty(Dll *list) { return list->head == NULL ? true : false; }

void insert_at_empty_list(Dll *list, Node *node) {
  list->head = node;
  list->tail = node;
  return;
}

void insert_at_head(Dll *list, uint data) {
  check_list(list);
  Node *node = init_node(data);
  // There is already an element in the list
  if (!is_empty(list)) {
    Node *old_head = list->head;
    node->next = old_head;
    old_head->previous = node;
    list->head = node;
    return;
  }
  insert_at_empty_list(list, node);
}

void delete_at_head(Dll *list) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  Node *node_to_delete = list->head;
  list->head = node_to_delete->next;
  list->head->previous = NULL;
  free(node_to_delete);
  return;
}

void insert_at_tail(Dll *list, uint data) {
  check_list(list);
  Node *node = init_node(data);
  if (!is_empty(list)) {
    Node *old_tail = list->tail;
    node->previous = old_tail;
    old_tail->next = node;
    list->tail = node;
    return;
  }
  insert_at_empty_list(list, node);
}

void delete_at_tail(Dll *list) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  Node *node_to_delete = list->tail;
  list->tail = node_to_delete->previous;
  list->tail->next = NULL;
  free(node_to_delete);
  return;
}

void insert_before(Dll *list, uint reference, uint data) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  Node *runner = list->head;
  while (runner != NULL && runner->next->data != reference) {
    runner = runner->next;
  }
  Node *new_node = init_node(data);
  Node *next = runner->next;
  new_node->previous = runner;
  new_node->next = next;
  runner->next = new_node;
  return;
}

void delete_element(Dll *list, uint reference) {
  check_list(list);
  if (is_empty(list)) {
    return;
  }
  Node *runner = list->head;
  while (runner != NULL && runner->next->data != reference) {
    runner = runner->next;
  }
  Node *node_to_delete = runner->next;
  node_to_delete->next->previous = node_to_delete->previous;
  node_to_delete->previous->next = node_to_delete->next;
  free(node_to_delete);
  return;
}

void print_list(Dll *list) {
  check_list(list);
  if (is_empty(list)) {
    printf("[]");
    return;
  }
  Node *runner = list->head;

  printf("[");
  while (runner != NULL) {
    if (runner->next == NULL) {
      printf("%u", runner->data);
    } else {
      printf("%u <-> ", runner->data);
    }

    runner = runner->next;
  }
  printf("]\n");
  return;
}
