#include <stdio.h>
#include <stdlib.h>

struct node {
 struct node *prev;
 int value;
 struct node *next;
};

struct linked_list {
 struct node *begin;
 int size;
};

void print_list(struct linked_list *list) {
 struct node *curr = list->begin;
 while (curr != NULL) {
  printf("%d ", curr->value);
  curr = curr->next;
 }
 printf("\n");
}

void insert_node(struct linked_list *list, int elem) {
 if(list->size == 0) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->prev = NULL;
  new_node->value = elem;
  new_node->next = NULL;
  list->begin = new_node;
  list->size++;
  printf("First node inserted\n");
 } else {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->prev = NULL;
  new_node->value = elem;
  new_node->next = list->begin;
  struct node *tmp = list->begin;
  tmp->prev = new_node;
  list->begin = new_node;
  list->size++;
  printf("New node inserted\n");
 }
}

int delete_node(struct linked_list *list, int val) {
 struct node *curr = list->begin;
 while(curr != NULL) {
  if(curr->value == val) {
   if(curr == list->begin)
    list->begin = curr->next;
   if(curr->prev != NULL)
    curr->prev->next = curr->next;
   if(curr->next != NULL)
    curr->next->prev = curr->prev;
   free(curr);
   return 1;
  }
  curr = curr->next;
 }
 return 0;
}

int main() {
 struct linked_list link_list = {.begin = NULL, .size = 0};
 insert_node(&link_list, 4);
 insert_node(&link_list, 2);
 insert_node(&link_list, 1);
 print_list(&link_list);
 delete_node(&link_list, 2);
 print_list(&link_list);
 delete_node(&link_list, 1);
 print_list(&link_list);
 delete_node(&link_list, 4);
 print_list(&link_list);
 return 0;
}
