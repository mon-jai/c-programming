#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct link_list_item {
  int value;
  struct link_list_item* next_item;
} LinkListItem;

LinkListItem* scan_and_push(LinkListItem** link_list_end_ptr) {
  int value;
  scanf(" %d", &value);

  LinkListItem* new_link_list_item = malloc(sizeof(LinkListItem));
  new_link_list_item->value = value;
  new_link_list_item->next_item = NULL;

  if (*link_list_end_ptr != NULL) (*link_list_end_ptr)->next_item = new_link_list_item;
  *link_list_end_ptr = new_link_list_item;

  return new_link_list_item;
}

void print_link_list(LinkListItem* link_list_head) {
  LinkListItem* link_list_current = link_list_head;

  while (true) {
    printf("%d ", link_list_current->value);
    link_list_current = link_list_current->next_item;
    if (link_list_current == NULL) break;
  }
  printf("\n");
}

int main() {
  LinkListItem* link_list_head = NULL;
  LinkListItem* link_list_end = NULL;

  int link_list_size;
  scanf("%d", &link_list_size);

  for (int i = 0; i < link_list_size; i++) {
    LinkListItem* new_link_list_item = scan_and_push(&link_list_end);
    if (i == 0) link_list_head = new_link_list_item;
  }
  getchar();

  print_link_list(link_list_head);

  // while (true) {
  //   int action;
  //   scanf("%d", &action);

  //   if (action == 1) {
  //     scan_and_push(&link_list_end);
  //   } else if (action == 2) {
  //     int insert_after;
  //     int value;

  //     scanf(" %d", &insert_after);
  //     scanf(" %d", &value);

  //     LinkListItem* link_list_current = link_list_head;
  //     while (true) {
  //       if (link_list_current->value == insert_after) break;
  //       link_list_current = link_list_current->next_item;
  //     }

  //     LinkListItem* new_link_list_item = malloc(sizeof(LinkListItem));
  //     new_link_list_item->value = value;
  //     new_link_list_item->next_item = link_list_current->next_item;

  //     link_list_current->next_item = new_link_list_item;
  //   } else if (action == 3) {

  //   } else if (action == 4) {

  //   } else if (action == 5) {

  //   } else if (action == 6) {
  //     break;
  //   }
  // }

  // print_link_list(link_list_head);
}