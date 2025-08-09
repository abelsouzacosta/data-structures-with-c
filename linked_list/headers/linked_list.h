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

Node *create_node(unsigned int data);

LinkedList *init_list(void);

void insert_at_tail(LinkedList *list, unsigned int data);

void insert_at_head(LinkedList *list, unsigned int data);

void list_lenth(LinkedList *list);

void print_list(LinkedList *list);

int get_tail(LinkedList *list);

int get_head(LinkedList *list);

#endif
