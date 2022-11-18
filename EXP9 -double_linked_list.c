// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
  int value;
  struct node *prev;
  struct node *next;
};

// print the linked list value from head
void printLinkedlist_head(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}
// print the linked list value from tail
void printLinkedlist_tail(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->prev;
  }
}

int main() {
  /* Initialize nodes */
  struct node *head;
  struct node *tail;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  
  /* Allocate memory */
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  
  /* Assign value values */
  one->value = 1;
  two->value = 2;
  three->value = 3;
  
  /* Connect nodes */
  one->next = two;
  one->prev = NULL;
  
  two->next = three;
  two->prev = one;
  
  three->next = NULL;
  three->prev = two;
  
  /* Save address of first node in head */
  head = one;
  tail = three;
  
  printf("Linked list contents from head: ");
  printLinkedlist_head(head);
  
  printf("\n");
  
  printf("Linked list contents from tail: ");
  printLinkedlist_tail(tail);
}