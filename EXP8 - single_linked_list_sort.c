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

// Sort the linked list
void sortLinkedList(struct node* head_ref) {
  struct node *current = head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
    return;
  } else {
    while (current != NULL) {
      // index points to the node next to current
      index = current->next;

  	while (index != NULL) {
        if (current->value > index->value) {
          temp = current->value;
          current->value = index->value;
          index->value = temp;
    	  }
    	  index = index->next;
  	}
  	current = current->next;
    }
  }
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
  two->value = 45;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;
  head = one;
  
  printf("Linked list before sorting is as follows: ");
  printLinkedlist(head);
  printf("\n");
  // Sort the linked list
  sortLinkedList(head); 
  
  printf("Linked list after sorting is as follows: ");
  printLinkedlist(head);
}