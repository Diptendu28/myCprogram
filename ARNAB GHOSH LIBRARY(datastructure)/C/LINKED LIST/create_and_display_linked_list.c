#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;

void createNode(){
    int n;
    node *ptr, *cptr;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0){
        return ;
    }
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    head = ptr;
    for(int i = 2; i <= n; i++){
        cptr = (node*)malloc(sizeof(node));
        if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
        }
        printf("Enter data: ");
        scanf("%d", &cptr->data);
        ptr->next = cptr;
        ptr = cptr;
    }
    ptr->next = NULL;
}

void display(){
    node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}


int main(void){
    int num, item;
    createNode();
    printf("The single linear linked list is: \n");
    display();
    return 0;
}