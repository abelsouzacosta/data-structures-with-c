#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

typedef struct Node {
  unsigned int data;
  struct Node *next;
} Node;

typedef struct CircularLinkedList {
  struct Node *head;
  struct Node *tail;
} CircularLinkedList;

Node *create_node(unsigned int data);

CircularLinkedList *init_list();

void insert_at_head(CircularLinkedList *list, unsigned int data);

void insert_at_tail(CircularLinkedList *list, unsigned int data);

void insert_after_element(CircularLinkedList *list, unsigned int data);

void delete_at_head(CircularLinkedList *list);

void delete_at_tail(CircularLinkedList *list);

void delete_element(CircularLinkedList *list, unsigned int reference);

void print_list(CircularLinkedList *list);

#endif
