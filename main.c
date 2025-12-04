#include "headers/ll.h"

int main(int argc, char *argv[]) {
  Sll *list = create_list();
  insert_at_tail(list, 1);
  insert_at_tail(list, 2);
  insert_at_tail(list, 3);
  insert_at_tail(list, 4);
  insert_at_tail(list, 5);
  insert_at_tail(list, 6);
  insert_at_tail(list, 7);
  insert_at_tail(list, 8);
  insert_at_tail(list, 9);
  insert_at_tail(list, 7);
  insert_at_tail(list, 10);
  insert_at_tail(list, 11);
  insert_at_tail(list, 7);
  insert_at_tail(list, 12);
  insert_at_tail(list, 4);
  insert_at_tail(list, 3);

  print_list(list);
  remove_duplicates(list);
  print_list(list);
  return 0;
}
