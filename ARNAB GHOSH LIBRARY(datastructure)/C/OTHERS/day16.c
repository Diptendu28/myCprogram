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
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL)
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
    temp->next = *head;
    temp->prev = NULL;

    while(ptr->next != NULL)
        ptr = ptr->next;

    temp->prev = ptr;
    ptr->next = temp;
    temp->next = NULL;
}


void insertAfter(node **head, int item){
    node *temp, *ptr;
    if(*head == NULL){
        printf("Insert atleast 1 value!!!\n");
        return;
    }
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;
    ptr = *head;
    while(ptr->next!=NULL){
        if(ptr->data == item){
            temp->prev = ptr;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            ptr->next = temp;
            printf("\ninserted after %d.\n", item);
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->data == item){
        while(ptr->next != NULL)
            ptr = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        temp->next = NULL;
        printf("\ninserted after %d.\n", item);
        return;
    }
    printf("Element not found!!!");
}

void fwd_Display(node **head){
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

void bwd_Display(node **head){
    node *ptr;
    ptr = *head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
        return;
    }
    while(ptr->next!=NULL)
        ptr = ptr->next;
    printf("\nLinked List in backward order:\n");
    while(ptr->prev!=NULL){
        printf("[%u|%u|%d|%u]<=>", ptr, ptr->next, ptr->data, ptr->prev);
        ptr = ptr->prev;
    }
    printf("[%u|%u|%d|%u]", ptr, ptr->next, ptr->data, ptr->prev);
}



int main(void){
    struct node *head = NULL;
    int num, key;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert Begin\n2) insert end\n3) insert after\n4) display forward\n5) display backward\n6) exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: insertBegin(&head);
                    printf("\ninserted at begin.\n");
                break;
            case 2: insertEnd(&head);
                    printf("\ninserted at end.\n");
                break;

            case 3: printf("\nEnter KEY: ");
                    scanf("%d", &key);
                    insertAfter(&head, key);
                break;

            case 4: fwd_Display(&head);
                break;

            case 5: bwd_Display(&head);
                break;

            case 6: exit(0);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}


/**


Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 1

Enter data: 1

inserted at begin.

Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 1

Enter data: 2

inserted at begin.

Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 1

Enter data: 3

inserted at begin.

Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 4

Linked List in forward order:
[8262648|0|3|8262584]<=>[8262584|8262648|2|8262560]<=>[8262560|8262584|1|0]
Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 2

Enter data: 5

inserted at end.

Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 4

Linked List in forward order:
[8262648|0|3|8262584]<=>[8262584|8262648|2|8262560]<=>[8262560|8262584|1|8262672]<=>[8262672|8262560
|5|0]
Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 3

Enter KEY: 2

Enter data: 10

inserted after 2.

Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 4

Linked List in forward order:
[8262648|0|3|8262584]<=>[8262584|8262648|2|8262696]<=>[8262696|8262584|10|8262560]<=>[8262560|826269
6|1|8262672]<=>[8262672|8262560|5|0]
Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose: 5

Linked List in backward order:
[8262672|0|5|8262560]<=>[8262560|8262672|1|8262696]<=>[8262696|8262560|10|8262584]<=>[8262584|826269
6|2|8262648]<=>[8262648|8262584|3|0]
Menu:
1) insert Begin
2) insert end
3) insert after
4) display forward
5) display backward
6) exit

Choose:6



*/
