#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

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


void print_list(DoublyLinkedList *list);

#endif
