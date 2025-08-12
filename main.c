#include "linked_list/headers/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  LinkedList *list = malloc(sizeof(LinkedList));

  insert_at_head(list, 10);
  insert_at_head(list, 20);
  insert_at_head(list, 30);
  insert_at_head(list, 40);
  insert_at_head(list, 50);
  insert_at_tail(list, 60);
  insert_at_tail(list, 70);
  insert_at_tail(list, 100);
  insert_at_head(list, 200);

  insert_after_element(list, 30, 300);
  insert_after_element(list, 100, 10000);

  print_list(list);
  printf("\nThe tail of the list is %u\n", get_tail(list));
  printf("\nThe head of the list is %u\n", get_head(list));

  // reverses the list
  reverse_list(list);

  print_list(list);
  printf("\nThe tail of the list is %u\n", get_tail(list));
  printf("\nThe head of the list is %u\n", get_head(list));

  free(list);
}
