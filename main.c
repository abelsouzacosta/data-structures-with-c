#include "headers/dll.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Dll *list = create_list();

  insert_at_head(list, 1);
  insert_at_head(list, 2);
  insert_at_head(list, 3);
  insert_at_head(list, 4);
  insert_at_head(list, 5);
  insert_at_head(list, 6);
  insert_at_head(list, 7);
  insert_at_head(list, 8);
  insert_at_head(list, 9);
  insert_at_head(list, 10);
  insert_at_head(list, 11);
  insert_at_head(list, 12);
  insert_at_head(list, 13);
  insert_at_head(list, 14);
  insert_at_head(list, 15);
  insert_at_head(list, 16);
  print_list(list);
  delete_at_head(list);
  print_list(list);
  delete_at_tail(list);
  print_list(list);
  insert_before(list, 10, 0);
  print_list(list);
  delete_element(list, 0);
  print_list(list);
  insert_at_tail(list, 1000);
  print_list(list);

  free(list);
  return 0;
}
