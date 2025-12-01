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

/**
 * insert_at_empty_list() - inserts a node in a empty list
 *
 * @list: a pointer to a singly linked list
 * @node: a pointer to a singly linked list node
 *
 * Return: void
 */
void insert_at_empty_list(Sll *list, LlNode *node);

/**
 * insert_at_head() - inserts a node with the data given in the head of the
 * singly linked list
 *
 * @list: a pointer to a singly linked list
 * @data: a unsigned integer
 *
 * Return: void
 */
void insert_at_head(Sll *list, uint data);

/**
 * insert_at_tail() - inserts a node with the data given in the tail of the
 * singly linked list
 *
 * @list: a pointer to a singly linked list
 * @data: a unsigned integer
 *
 * Return: void
 */

void insert_at_tail(Sll *list, uint data);

/**
 * delete_at_head() - deletes the node at the head of the list
 *
 * @list: a pointer to a singly linked list
 *
 * Return: void
 */
void delete_at_head(Sll *list);
#endif
