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

