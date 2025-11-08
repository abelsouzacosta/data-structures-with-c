#include "linked_list/headers/linked_list.h"

int main(int argc, char *argv[]) {
  LinkedList *list = init_list();
  insert_at_head(list, 1);
  insert_at_head(list, 3);
  insert_at_head(list, 2);
  insert_at_tail(list, 4);
  insert_at_tail(list, 5);
  print_list(list);
  reverse_list(list);
  print_list(list);
  reverse_first(list, 3);
  print_list(list);
  return 0;
}
