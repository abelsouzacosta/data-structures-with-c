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

/**
 * create_list() - allocates a new doubly linked list
 *
 * Return: a malloced doubly linked list
 */
DoublyLinkedList *create_list(void);

/**
 * init_node() - allocates a new node
 *
 * @data: the value carried by the node
 *
 * Return: a malloced node with previous and next pointing to NULL positions
 */
Node *init_node(uint data);

/**
 * insert_at_head() - inserts a new node at the head of the list
 *
 * @list: a pointer to a doubly linked list
 * @data: a uint value
 *
 * Return: void
 */
void insert_at_head(DoublyLinkedList *list, uint data);

/**
 * insert_at_tail() - inserts a new node at the tail of the list
 *
 * @list: a pointer to a doubly linked list
 * @data: a uint value
 */
void insert_at_tail(DoublyLinkedList *list, uint data);

/**
 * insert_before() - inserts a new node before the first node that holds the
 * reference value
 *
 * @list: a pointer to a doubly linked list
 * @reference: a reference value that will be used in the comparison
 * @data: a uint value
 *
 * Return: void
 */
void insert_before(DoublyLinkedList *list, uint reference, uint data);

/**
 * insert_after() - inserts a new node after the first node that holds the
 * reference value
 *
 * @list: a pointer to a doubly linked list
 * @reference: a reference value that will be used in the comparison
 * @data: a uint value
 *
 * Return: void
 */
void insert_after(DoublyLinkedList *list, uint reference, uint data);

/**
 * delete_at_head() - frees the malloced node at the head of the list and sets
 * its next reference as the new head
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: void
 */
void delete_at_head(DoublyLinkedList *list);

/**
 * delete_at_tail() - frees the malloced node at the tail of the list and sets
 * its previous reference as the new tail
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: void
 */
void delete_at_tail(DoublyLinkedList *list);

/**
 * delete_element() - frees the first node that holds the reference given
 *
 * @list: a pointer to a doubly linked list
 * @reference: a reference value that will be used in the comparison
 *
 * Return: void
 */
void delete_element(DoublyLinkedList *list, uint reference);

/**
 * delete_all_references() - frees all the nodes that holds the reference given
 *
 * @list: a pointer to a doubly linked list
 * @reference: a reference value that will be used in the comparison
 *
 * Return: void
 */
void delete_all_references(DoublyLinkedList *list, uint reference);

/**
 * reverse() - reverse the list making swapping between head and tail
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: void
 */
void reverse(DoublyLinkedList *list);

/**
 * reverse_first() - reverse the first n positions given
 *
 * @list: a pointer to a doubly linked list
 * @positions: the number of positions to be reverted
 *
 * Return: void
 */
void reverse_first(DoublyLinkedList *list, uint positions);

/**
 * swap() - will swap the two first elements
 *
 * @list: a pointer to a doubly linked list
 *
 * Return: void
 */
#endif // !DOUBLYLINKEDLIST
