//7. a) Write a program to create a double linked list and find out the sum of  all nodes of the list.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;


void insert(node **head){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL)
        (*head)->prev = temp;
    *head = temp;
}



void display(node **head){
    node *ptr;
    ptr = *head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
        return;
    }
    printf("\nLinked List in forward order:\n");
    while(ptr->next!=NULL){
        printf("[%u|%u|%d|%u]<=>", ptr, ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }
    printf("[%u|%u|%d|%u]", ptr, ptr->prev, ptr->data, ptr->next);
}


void sum_of_node(node *head){
    int sum = 0;
    if(head == NULL){
        printf("\nLinked list is empty!!!\n");
        return ;
    }
    while(head != NULL){
        sum += head->data;
        head = head->next;
    }
    printf("\nSum of all nodes is %d\n", sum);
}

int main(void){
    struct node *head = NULL;
    int num, key;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert\n2) display\n3) sum of all nodes\n4) exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){

            case 1: insert(&head); break;

            case 2: display(&head); break;

            case 3: sum_of_node(head); break;

            case 4:  free(head); exit(0); break;

            default: printf("Invalid Input");
        }
    }
    free(head);
    return 0;
}
