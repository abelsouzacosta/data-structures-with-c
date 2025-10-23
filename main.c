
#include "circular_linked_list/headers/circular_linked_list.h"
int main(int argc, char *argv[]) {
  CircularLinkedList *list = init_list();
  insert_at_head(list, 1);
  insert_at_head(list, 3);
  insert_at_head(list, 2);
  print_list(list);
  return 0;
}
