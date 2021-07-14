#include <stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node{ 
    int data; 
    struct node* next; 
} node; 

node *head = NULL;

node* setNode(node *ptr, int val){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
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

int isPrime(int n){ 
    for(int i = 2; i < sqrt(n); i++)
        if(n%i == 0)
            return 0;
    return 1;
} 

node* deleteSpecificNode(int item){
    node *ptr, *cptr;
    ptr = head;
    while(ptr->next != NULL){
        if(head->data == item){
            cptr = head;
            head = head->next;
            free(cptr);
            return head;
        }
        if(ptr->next->data == item){
            cptr = ptr->next;
            ptr->next = cptr->next;
            free(cptr);
            return head;
        }
        ptr = ptr->next;
    }
}

node* deletePrimeNodes(){ 
    node* tptr = head;
    while(tptr != NULL){
        if(isPrime(tptr->data)){
            tptr = deleteSpecificNode(tptr->data);
            continue;
        }
        tptr = tptr->next;
    }
    return head;    
}

int main(void){
    int t;
    node *ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    printf("Insert %d values:--\n", t);
    while(t--){
        int val;
        scanf("%d", &val);
        ptr = addNode(val);
    }
    printf("The Linked List is: \n");
    display(ptr);
    ptr = deletePrimeNodes();
    printf("The updated Linked List is: \n");
    display(ptr);
    return 0;
}