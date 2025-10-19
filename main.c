#include "doubly_linked_list/headers/doubly_linked_list.h"

int main(int argc, char *argv[]) {
  DoublyLinkedList *list = init_list();
  insert_at_head(list, 3);
  insert_at_head(list, 2);
  insert_at_head(list, 1);
  insert_at_tail(list, 4);
  print_list(list);
}
