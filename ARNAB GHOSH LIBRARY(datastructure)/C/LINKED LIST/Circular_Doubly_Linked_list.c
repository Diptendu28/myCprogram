#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;

void insertBegin(node **head){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);

    if(*head == NULL){
       temp->prev = temp;
       temp->next = temp;
       *head = temp;
       return;
    }

    temp->next = *head;
    (*head)->prev->next = temp;
    temp->prev = (*head)->prev;
    (*head)->prev = temp;
    *head = temp;
}


void insertEnd(node **head){
    node *ptr, *temp;
    ptr = *head;

    if(*head == NULL){
        insertBegin(head);
        return;
    }

    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    ptr = (*head)->prev;
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = *head;
    (*head)->prev = temp;
}



void display(node **head){
    node *ptr;
    ptr = *head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
        return;
    }
    printf("\nLinked List in forward order:\n");
    if(ptr == ptr->next){
        printf("[C:%u|P:%u|D:%d|N:%u]", ptr, ptr->prev, ptr->data, ptr->next);
        return;
    }
    do{
        printf("[C:%u|P:%u|D:%d|N:%u]<=>", ptr, ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }while(ptr->next!= *head);
    printf("[C:%u|P:%u|D:%d|N:%u]", ptr, ptr->prev, ptr->data, ptr->next);
}



void rev_display(node **head){
    if(*head == NULL){
        printf("\nNothing to print\n");
        return;
    }
    node *ptr;
    ptr = (*head)->prev;
    printf("\nLinked List in reverse order:\n");
    if(ptr == ptr->next){
        printf("[C:%u|P:%u|D:%d|N:%u]", ptr, ptr->next, ptr->data, ptr->prev);
        return;
    }
    do{
        printf("[C:%u|P:%u|D:%d|N:%u]<=>", ptr, ptr->next, ptr->data, ptr->prev);
        ptr = ptr->prev;
    }while(ptr!= *head);
    printf("[C:%u|P:%u|D:%d|N:%u]", ptr, ptr->next, ptr->data, ptr->prev);
}


void insertAfter(node **head, int item){
    node *ptr,*temp;
    ptr = *head;
    if(ptr == NULL){
        printf("Insert data first!!!");
        return;
    }
    do{
        if(ptr->data == item){
            temp = (node*)malloc(sizeof(node));
            printf("\nEnter data: ");
            scanf("%d", &temp->data);
            temp->prev = ptr;
            temp->next = ptr->next;
            ptr->next = temp;
            temp->next->prev = temp;
            printf("\ndata inserted after %d.\n", item);
            return;
        }
        ptr = ptr->next;
    }while(ptr->next != *head);
    if(ptr->data == item){
        insertEnd(head);
        printf("\ndata inserted after %d.\n", item);
        return;
    }
    printf("%d is not present in the list\n", item);

}


void deleteSpecific(node **head, int item){
    node *ptr, *temp;
    ptr = *head;
    if (ptr == NULL){
        printf("Nothing to delete");
        return;
    }

    if(ptr == ptr->next && ptr == ptr->prev && ptr->data == item){ // problem at this line
        *head = NULL;
        printf("\n%d deleted from the Linked list\n", item);
        return;
    }
    if(ptr->data == item){
        (*head)->next->prev = (*head)->prev;
        (*head)->prev->next = (*head)->next;
        (*head) = (*head)->next;
        ptr->prev = NULL;
        ptr->next = NULL;
        free(ptr);
        printf("\n%d deleted from the Linked list\n", item);
        return;
    }
    do{
        if(ptr->data == item){
            temp = ptr->next;
            temp->prev = ptr->prev;
            ptr->prev->next = temp;
            ptr->next->prev = temp;
            ptr->prev=NULL;
            ptr->next=NULL;
            printf("\n%d deleted from the Linked list\n", item);
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }while(ptr->next != *head);
    if(ptr->data==item){
        ptr = (*head)->prev;
        ptr->prev->next = *head;
        (*head)->prev = ptr->prev;
        ptr->prev = NULL;
        ptr->next = NULL;
        free(ptr);
        printf("\n%d deleted from the Linked list\n", item);
        return;
    }
    printf("%d is not present in the list", item);
}


int main(void){
    struct node *head = NULL;
    int num, key;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert Begin\n2) insert end\n3) insert after\n4) exit\n5) display\n6) reverse display\n7) delete\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: insertBegin(&head);
                    printf("\ninserted at begin.\n");
                break;
            case 2: insertEnd(&head);
                    printf("\ninserted at end.\n");
                break;

            case 3: printf("Enter the KEY: "); 
                    scanf("%d", &key);
                    insertAfter(&head, key);
                break;

            case 7: printf("\nEnter KEY: ");
                    scanf("%d", &key);
                    deleteSpecific(&head, key);
                break;

            case 4: exit(0);
                break;

            case 5: display(&head);
                break;

            case 6: rev_display(&head);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}
