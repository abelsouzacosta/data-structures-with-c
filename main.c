#include "headers/doubly_linked_list.h"

int main() {
  DoublyLinkedList *list = init_list();
  insert_at_head(list, 2);
  insert_at_head(list, 3);
  insert_at_head(list, 4);
  insert_at_head(list, 5);
  reverse(list);
  print_list(list);
  return 0;
}
