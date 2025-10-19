#include "doubly_linked_list/headers/doubly_linked_list.h"

int main(int argc, char *argv[]) {
  DoublyLinkedList *list = init_list();
  insert_at_head(list, 3);
  insert_at_head(list, 2);
  insert_at_head(list, 1);
  insert_at_tail(list, 4);
  insert_after_element(list, 2, 10);
  print_list(list);
  delete_at_head(list);
  print_list(list);
  delete_at_tail(list);
  print_list(list);
  delete_element(list, 10);
  print_list(list);

  DoublyLinkedList *new_list = init_list();
  insert_at_head(new_list, 3);
  insert_at_head(new_list, 3);
  insert_at_head(new_list, 4);
  insert_at_head(new_list, 10);
  insert_at_head(new_list, 3);
  insert_at_head(new_list, 1);

  print_list(new_list);
  // must remove all occurrences of 3 in the list
  delete_all_occurrences(new_list, 3);
  print_list(new_list);

  return 0;
}
