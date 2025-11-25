#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *previous;
  struct Node *next;
} Node;

typedef struct DoublyLinkedList {
  struct Node *head;
  struct Node *tail;
} DoublyLinkedList;

DoublyLinkedList *init_list(void);

Node *create_node(unsigned int data);

void insert_at_head(DoublyLinkedList *list, unsigned int data);

void insert_at_tail(DoublyLinkedList *list, unsigned int data);

void insert_after_element(DoublyLinkedList *list, unsigned int reference,
                          unsigned int data);

void delete_at_head(DoublyLinkedList *list);

void delete_at_tail(DoublyLinkedList *list);

void delete_element(DoublyLinkedList *list, unsigned int reference);

void delete_all_occurrences(DoublyLinkedList *list, unsigned int reference);

void delete_adjacent_duplicates(DoublyLinkedList *list);

bool is_list_empty(DoublyLinkedList *list);

bool is_list_unary(DoublyLinkedList *list);

void print_list(DoublyLinkedList *list);

void reverse(DoublyLinkedList *list);

#endif
