/*
 * Program  : stack using linked list
 * Language : c
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    //create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = val;

    //make the new node points to the head node
    newNode->next = head;

    //make the new node as head node
    //so that head will always point the last inserted data
    head = newNode;
}

void pop()
{
    //temp is used to free the head node
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->value);

        //backup the head node
        temp = head;

        //make the head node points to the next node.
        //logically removing the node
        head = head->next;

        //free the poped element's memory
        free(temp);
    }
}

//print the linked list
void printList()
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->value);
         temp = temp->next;
    }
    printf("NULL\n");
}

void removeDuplicates()
{
    struct node *currentNode = head;

    while(currentNode != NULL)
    {
         struct node *nextNode = currentNode->next;
         struct node *before = currentNode;
         while(nextNode!=NULL){
                struct node *after = nextNode->next;
                if(currentNode->value == nextNode->value){
                    struct node *temp = currentNode;
                    before->next = after;
                    nextNode=after;
                }else{
                    before = nextNode;
                    nextNode = nextNode->next;
                }
         }
         currentNode = currentNode->next;
    }

}

int main()
{
    time_t t;

    srand((unsigned)time(&t));
    for(int i=0;i<15;i++){
     push(rand()%5);
    }
    printf("Linked List\n");
    printList();
    removeDuplicates();
    printf("After removing duplicates, the new linked list\n");
    printList();

    return 0;
}
