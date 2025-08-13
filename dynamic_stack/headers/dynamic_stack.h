#ifndef DYNAMIC_STACK
#define DYNAMIC_STACK

#include "../../linked_list/headers/linked_list.h"
#include <stdbool.h>

typedef struct DStack {
  Node *top;
  LinkedList *elements;
} DStack;

#endif // !DYNAMIC_STACK
