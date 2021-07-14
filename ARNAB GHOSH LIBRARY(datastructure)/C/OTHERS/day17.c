#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;


void insert(node **head){
    node *ptr, *temp;
    ptr = *head;

    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;

    if(*head == NULL){
        *head = temp;
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    temp->prev = ptr;
    ptr->next = temp;
    temp->next = NULL;
}



void Display(node **head){
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



void reverse(node** head){
    node *temp, *current;
    temp = NULL;
    current = *head;
    if(current->next == NULL){ // if one node is present then 'next' and 'prev' both are null so no need to reverse
        printf("\nLinked list is reversed!!!\n");
        return;
    }
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    *head = temp->prev;
    printf("\nLinked list is reversed!!!\n");
}


void deleteSpecific(node **head){
    node *ptr = *head;
    int item;
    printf("\nEnter the key: ");
    scanf("%d", &item);
    if((*head)->data == item){
        (*head)->next->prev = NULL;
        *head = (*head)->next;
        ptr->next = NULL;
        free(ptr);
        printf("\nElelment Deleted!!!\n");
        return;
    }
    while(ptr->next != NULL){
        if(ptr->data == item){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            printf("\nElelment Deleted!!!\n");
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->data == item){
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        free(ptr);
        printf("\nElelment Deleted!!!\n");
        return;
    }
    printf("\nElement not found!!!\n");
}


int main(void){
    struct node *head = NULL;
    int num, key;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert\n2) display\n3) exit\n4) reverse\n5) delete specific\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: insert(&head);
                    printf("\ninserted at begin.\n");
                break;

            case 2: Display(&head);
                break;

            case 3: exit(0);
                break;

            case 4: reverse(&head);
                break;

            case 5: deleteSpecific(&head);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}


/**


Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 1

Enter data: 1

inserted at begin.

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 1

Enter data: 2

inserted at begin.

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197024|0|1|8197048]<=>[8197048|8197024|2|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 1

Enter data: 3

inserted at begin.

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 1

Enter data: 4

inserted at begin.

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 1

Enter data: 5

inserted at begin.

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197024|0|1|8197048]<=>[8197048|8197024|2|8197112]<=>[8197112|8197048|3|8197136]<=>[8197136|8197112
|4|8197160]<=>[8197160|8197136|5|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 5

Enter the key: 1

Elelment Deleted!!!

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197048|0|2|8197112]<=>[8197112|8197048|3|8197136]<=>[8197136|8197112|4|8197160]<=>[8197160|8197136|5|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 5

Enter the key: 5

Elelment Deleted!!!

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197048|0|2|8197112]<=>[8197112|8197048|3|8197136]<=>[8197136|8197112|4|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 5

Enter the key: 3

Elelment Deleted!!!

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 5

Enter the key: 55

Element not found!!!

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197048|0|2|8197136]<=>[8197136|8197048|4|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 4

Linked list is reversed!!!

Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 2

Linked List in forward order:
[8197136|0|4|8197048]<=>[8197048|8197136|2|0]
Menu:
1) insert
2) display
3) exit
4) reverse
5) delete specific

Choose: 3


*/
