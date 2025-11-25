#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <stdbool.h>
#include <sys/types.h>

// node structure for a doubly linked list
typedef struct Node {
  Node *previous;
  Node *next;
  uint data;
} Node;

// doubly linked list structure
typedef struct DoublyLinkedList {
  Node *head;
  Node *tail;
} DoublyLinkedList;

/**
 * is_empty() - tells if a list is empty
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: a boolean value. true if the list is empty and false otherwise
 */
bool is_empty(DoublyLinkedList *list);

/**
 * is_unary() - tells if a list is unary
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: a boolean value. true if the list is unary false otherwise
 */
bool is_unary(DoublyLinkedList *list);

#endif // !DOUBLYLINKEDLIST
