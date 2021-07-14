#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node* setNode(node *ptr){
    ptr = (node*)malloc(sizeof(node)); 
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void display(node *ptr){
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}


node* addNode(int value, node* temp_head){
    node *temp, *ptr;
    temp = setNode(temp);
    temp->data = value;
     if(temp_head == NULL){
        temp_head = temp;
     } 
      
    else{
        ptr = setNode(ptr);
        ptr = temp_head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    } 
    return temp_head;
}

void updateHead(node *ptr, node *head, int val){
    head = ptr = addNode(val, head);
}

int main(void){
    node *head1= NULL;
    node *head2 = NULL;
    node *LL1, *LL2;
    // LL1 = addNode(10, head1);
    // head1 = LL1;
    // LL1 = addNode(30, head1);
    // head1 = LL1;
    // LL2 = addNode(20, head2);
    // head2 = LL2;
    // LL2 = addNode(40, head2);
    // head2 = LL2;
    updateHead(LL1, head1, 10);
    printf("Values of LL1\n");
    display(LL1);
    // printf("Values of LL2\n");
    // display(LL2);   
    return 0;
}