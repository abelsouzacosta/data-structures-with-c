#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node {
  unsigned int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  struct Node *head;
  struct Node *tail;
} LinkedList;

#endif
