#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct LlNode {
  struct LlNode *next;
  uint data;
} LlNode;

typedef struct SinglyLinkedList {
  struct LlNode *head;
  struct LlNode *tail;
} Sll;


#endif
