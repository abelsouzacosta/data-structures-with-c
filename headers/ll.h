#ifndef LINKEDLIST
#define LINKEDLIST

#include <sys/types.h>

typedef struct LlNode {
  struct LlNode *next;
  uint data;
} LlNode;

typedef struct SinglyLinkedList {
  struct LlNode *head;
  struct LlNode *tail;
} Sll;

/**
 * create_list() - allocates a new singly linked list
 *
 * Return a malloced singly linked list
 */
Sll create_list(void);

/**
 * init_node() - allocates a new node
 *
 * @data: the value carried by the node
 *  Return: a malloced node with next set to NULL
 */
LlNode init_node(uint data);

/**
 * check_list() - checks if the list is properly malloced
 *
 * @list: a pointer to a singly linked list
 *
 * Return: void
 */
void check_list(Sll *list);

/**
 * is_empty() - checks if the list is empty
 *
 * @list: a pointer to a singly linked list
 *
 * Return: void
 */
bool is_empty(Sll *list);

/**
 * is_unary() - checks if the list is unary
 *
 * @list: a pointer to a singly linked list
 *
 * Return: void
 */
bool is_unary(Sll *list);


#endif
