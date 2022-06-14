#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_item {
  int value;
  struct linked_list_item* next_item;
} LinkListItem;

LinkListItem* scan_and_push(LinkListItem** linked_list_end_ptr) {
  int value;
  scanf(" %d", &value);

  LinkListItem* new_linked_list_item = malloc(sizeof(LinkListItem));
  new_linked_list_item->value = value;
  new_linked_list_item->next_item = NULL;

  if (*linked_list_end_ptr != NULL) (*linked_list_end_ptr)->next_item = new_linked_list_item;
  *linked_list_end_ptr = new_linked_list_item;

  return new_linked_list_item;
}

void print_linked_list(LinkListItem* linked_list_head) {
  if (linked_list_head == NULL) {
    printf("None any node\n");
    return;
  }
  printf("List: ");
  LinkListItem* linked_list_current = linked_list_head;

  while (true) {
    printf("%d ", linked_list_current->value);
    linked_list_current = linked_list_current->next_item;
    if (linked_list_current == NULL) break;
  }
  printf("\n");
}

int main() {
  LinkListItem* linked_list_head = NULL;
  LinkListItem* linked_list_end = NULL;

  int linked_list_size;
  scanf("%d", &linked_list_size);

  for (int i = 0; i < linked_list_size; i++) {
    LinkListItem* new_linked_list_item = scan_and_push(&linked_list_end);
    if (i == 0) linked_list_head = new_linked_list_item;
  }
  getchar();

  while (true) {
    int action;
    scanf("%d", &action);

    printf("%d\n", action);

    print_linked_list(linked_list_head);

    if (action == 1) {

      scan_and_push(&linked_list_end);

    } else if (action == 2) {

      int insert_after;
      scanf(" %d", &insert_after);
      int value;
      scanf(" %d", &value);

      LinkListItem* linked_list_current = linked_list_head;
      while (true) {
        if (linked_list_current->value == insert_after) {
          break;
        } else if (linked_list_current->next_item == NULL) {
          linked_list_current = NULL;
          break;
        }
        linked_list_current = linked_list_current->next_item;
      }

      if (linked_list_current == NULL) continue;

      LinkListItem* new_linked_list_item = malloc(sizeof(LinkListItem));
      new_linked_list_item->value = value;
      new_linked_list_item->next_item = linked_list_current->next_item;

      linked_list_current->next_item = new_linked_list_item;
      if (linked_list_current == linked_list_end) linked_list_end = new_linked_list_item;
    } else if (action == 3) {

      int value_to_remove;
      scanf(" %d", &value_to_remove);

      if (linked_list_head->value == value_to_remove) {
        LinkListItem* next_item = linked_list_head->next_item;
        free(linked_list_head);
        linked_list_head = next_item;
      } else {
        LinkListItem* linked_list_current = linked_list_head;
        while (true) {
          if (linked_list_current->next_item == NULL) {
            linked_list_current = NULL;
            break;
          } else if (linked_list_current->next_item->value == value_to_remove) {
            break;
          }

          linked_list_current = linked_list_current->next_item;
        }

        if (linked_list_current == NULL) continue;

        LinkListItem* item_to_remove = linked_list_current->next_item;
        linked_list_current->next_item = item_to_remove->next_item;
        free(item_to_remove);
      }

    } else if (action == 4) {

      if (linked_list_head == linked_list_end) continue;

      LinkListItem* next_item = linked_list_head->next_item;
      free(linked_list_head);
      linked_list_head = next_item;

    } else if (action == 5) {

      if (linked_list_head == linked_list_end) continue;

      LinkListItem* linked_list_current = linked_list_head;
      while (true) {
        if (linked_list_current->next_item == linked_list_end) break;
        linked_list_current = linked_list_current->next_item;
      }

      if (linked_list_current == linked_list_head) {
        linked_list_head = NULL;
      } else {
        linked_list_current->next_item = NULL;
        linked_list_end = linked_list_current;
      }

      free(linked_list_end);

    } else if (action == 6) {
      break;
    }

    if (linked_list_head == NULL) linked_list_end = NULL;

    print_linked_list(linked_list_head);
  }

  print_linked_list(linked_list_head);
}