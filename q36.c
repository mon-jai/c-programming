#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_item {
  int value;
  struct linked_list_item* next_item;
} LinkListItem;

LinkListItem* push(LinkListItem** linked_list_head_ptr, LinkListItem** linked_list_end_ptr) {
  int value;
  scanf(" %d", &value);

  LinkListItem* new_linked_list_item = malloc(sizeof(LinkListItem));
  new_linked_list_item->value = value;
  new_linked_list_item->next_item = NULL;

  if (*linked_list_head_ptr == NULL) *linked_list_head_ptr = new_linked_list_item;
  if (*linked_list_end_ptr != NULL) (*linked_list_end_ptr)->next_item = new_linked_list_item;
  *linked_list_end_ptr = new_linked_list_item;

  return new_linked_list_item;
}

void insert_after_item(LinkListItem** linked_list_head_ptr, LinkListItem** linked_list_end_ptr) {
  int insert_after;
  scanf(" %d", &insert_after);
  int value;
  scanf(" %d", &value);

  if (*linked_list_head_ptr == NULL) return;

  LinkListItem* item_to_insert_after;
  LinkListItem* new_linked_list_item = malloc(sizeof(LinkListItem));
  new_linked_list_item->value = value;

  item_to_insert_after = *linked_list_head_ptr;
  while (true) {
    if (item_to_insert_after->value == insert_after) break;
    if (item_to_insert_after->next_item == NULL) return;

    item_to_insert_after = item_to_insert_after->next_item;
  }

  new_linked_list_item->next_item = item_to_insert_after->next_item;
  item_to_insert_after->next_item = new_linked_list_item;
  if (item_to_insert_after == *linked_list_end_ptr) *linked_list_end_ptr = new_linked_list_item;
}

void remove_item(LinkListItem** linked_list_head_ptr, LinkListItem** linked_list_end_ptr) {
  int value_to_remove;
  scanf(" %d", &value_to_remove);

  if ((*linked_list_head_ptr)->value == value_to_remove) {

    LinkListItem* next_item = (*linked_list_head_ptr)->next_item;
    free(*linked_list_head_ptr);
    *linked_list_head_ptr = next_item;

  } else {

    LinkListItem* item_before_item_to_remove = *linked_list_head_ptr;
    while (true) {
      if (item_before_item_to_remove->next_item == NULL) return;
      if (item_before_item_to_remove->next_item->value == value_to_remove) break;

      item_before_item_to_remove = item_before_item_to_remove->next_item;
    }

    LinkListItem* item_to_remove = item_before_item_to_remove->next_item;
    item_before_item_to_remove->next_item = item_to_remove->next_item;
    if (*linked_list_end_ptr == item_to_remove) *linked_list_end_ptr = item_before_item_to_remove;

    free(item_to_remove);
  }
}

void shift(LinkListItem** linked_list_head_ptr, LinkListItem** linked_list_end_ptr) {
  if (*linked_list_head_ptr == NULL) return;

  LinkListItem* first_item = *linked_list_head_ptr;
  LinkListItem* second_item = (*linked_list_head_ptr)->next_item;
  *linked_list_head_ptr = second_item;
  if (second_item == NULL) *linked_list_end_ptr = NULL;

  free(first_item);
}

void pop(LinkListItem** linked_list_head_ptr, LinkListItem** linked_list_end_ptr) {
  if (*linked_list_head_ptr == NULL) return;

  if (*linked_list_head_ptr == *linked_list_end_ptr) {

    *linked_list_head_ptr = NULL;
    *linked_list_end_ptr = NULL;

  } else {

    LinkListItem* item_before_last_item = *linked_list_head_ptr;
    while (true) {
      if (item_before_last_item->next_item == *linked_list_end_ptr) break;
      item_before_last_item = item_before_last_item->next_item;
    }

    LinkListItem* linked_list_last_item = item_before_last_item->next_item;
    item_before_last_item->next_item = NULL;
    *linked_list_end_ptr = item_before_last_item;

    free(linked_list_last_item);
  }
}

void print_linked_list(LinkListItem* linked_list_head) {
  if (linked_list_head == NULL) {
    printf("None any node\n");
    return;
  }

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
    push(&linked_list_head, &linked_list_end);
  }
  getchar();

  while (true) {
    int action;
    scanf("%d", &action);

    if (action == 1) push(&linked_list_head, &linked_list_end);
    else if (action == 2) insert_after_item(&linked_list_head, &linked_list_end);
    else if (action == 3) remove_item(&linked_list_head, &linked_list_end);

    else if (action == 4) shift(&linked_list_head, &linked_list_end);
    else if (action == 5) pop(&linked_list_head, &linked_list_end);

    else if (action == 6) break;
  }

  print_linked_list(linked_list_head);
}
