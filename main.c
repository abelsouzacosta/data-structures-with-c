#include "headers/linked_list.h"

int main() {
  LinkedList *list = init_list();
  insert_at_head(list, 1);
  insert_at_head(list, 3);
  insert_at_head(list, 2);
  insert_at_tail(list, 4);
  insert_at_tail(list, 5);
  print_list(list);
  remove_duplicates(list);
  print_list(list);
  return 0;
}
