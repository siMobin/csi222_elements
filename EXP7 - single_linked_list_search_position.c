// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
  int value;
  struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}

int searchNode(struct node* head_ref, int key) {
  struct node* current = head_ref;
  int position = 1;
  while (current != NULL) {
    if (current->value == key) return position;
    current = current->next;
    position++;
  }
  return 0;
}

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign value
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;
  head = one;
  
  // Search a node and return position
  int position = searchNode(head, 3);
  
  if(position==0){
          printf("Item not found.");
  }else{
          printf("Item found at postion %d", position);
  }
}