#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *oddhead = NULL;
node *evenhead = NULL;

node* setNode(node *ptr, int val){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void doTheWork(node *temp_head, int val){
    node *temp, *cptr;
    temp = setNode(temp, val);
    cptr = temp_head;
    while(cptr->next != NULL)
        cptr = cptr->next;
    cptr->next = temp;
}

node* addNode(int value){
    node *temp,*ptr;
    temp = setNode(temp, value);
     if(head == NULL)
        head = temp;
    else{
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    } 
    return head;
}

void separateOddEven(){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->data % 2 == 1){
            if(oddhead == NULL)
                oddhead = setNode(oddhead, ptr->data);            
            else
                doTheWork(oddhead, ptr->data);
        }
        else{
            if(evenhead == NULL)
                evenhead = setNode(evenhead, ptr->data);            
            else                
                doTheWork(evenhead, ptr->data);
        }
        ptr = ptr->next;
    }
}

void display(node *ptr){
    if(ptr == NULL){
        printf("Nothing to Print\n");
        return ;
    }
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

int main(void){
    int t;
    node* ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    printf("Insert %d values:--\n", t);
    while(t--){
        int val;
        scanf("%d", &val);
        ptr = addNode(val);
    }
    separateOddEven();
    printf("The original Linked List:\n");
    display(head);
    printf("The odd elements are:\n");
    display(oddhead);
    printf("The even elements are:\n");
    display(evenhead);
    return 0;
}