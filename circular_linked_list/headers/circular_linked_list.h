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


#endif
