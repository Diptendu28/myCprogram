/*circular doubly*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insert_begining(struct node **head)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &ptr->data);
    if (*head == NULL)
    {
        *head = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
    }
    else
    {
        ptr->next = *head;
        ptr->prev = (*head)->prev;
        (*head)->prev = ptr;
        ptr->prev->next=ptr;
        *head = ptr;
        
    }
}
void insert_end(struct node **head)
{
    struct node *ptr, *cptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &ptr->data);
    if (*head == NULL)
    {
        *head = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return;
    }
    ptr->prev=(*head)->prev;
    (*head)->prev->next=ptr;
    ptr->next=(*head);
    (*head)->prev=ptr;
}

void insert_after(struct node **head)
{
    struct node *ptr, *cptr;
    int element;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter the element in the list you want to insert after:");
    scanf("%d", &element);
    printf("enter data:");
    scanf("%d", &ptr->data);
    cptr = *head;
    while (cptr->next != (*head))
    {
        if (cptr->data == element)
        {
            ptr->prev = cptr;
            ptr->next = cptr->next;
            cptr->next->prev = ptr;
            cptr->next = ptr;
            return;
        }
        cptr = cptr->next;
    }

    if (cptr->data == element)
    {
        cptr->next = ptr;
        ptr->prev = cptr;
        ptr->next = (*head);
        (*head)->prev=ptr;
    }
    else
    {
        printf("Element not found");
    }
}
void delete_node(struct node **head)
{
    int item;
    struct node *cptr, *ptr;
    if (*head == NULL)
    {
        printf("Nothing to delete");
        return;
    }
    printf("\nenter the node to be deleted:");
    scanf("%d", &item);
    if((*head)->data==item&&(*head)->next==(*head))
    {
        (*head)=NULL;
        return;
    }
    if((*head)->data==item)
    {
        (*head)->next->prev=(*head)->prev;
        (*head)->prev->next=(*head)->next;
        (*head)=(*head)->next;
        return;
    }
    ptr =*head;cptr=(*head)->next;
    while (cptr->next != (*head))
    {
        if (cptr->data == item)
        {
            ptr->next=cptr->next;
            cptr->next->prev=ptr;
            cptr->prev=NULL;
            cptr->next=NULL;
            printf("deleted element is %d\n", cptr->data);
            free(cptr);
            return;
        }
        ptr = cptr;
        cptr = cptr->next;
    }
    if(cptr->data==item)
    {
        printf("deleted element is %d\n", cptr->data);
        cptr->prev->next=(*head);
        (*head)->prev=cptr->prev;
        cptr->prev=NULL;
        free(cptr);
        return;
    }
    printf("element not found");
}
void display(struct node **head)
{
    struct node *ptr;
    if(*head==NULL)
    {
        printf("nothing to display\n");
        return;
    }
    ptr = *head;
    printf("in forward direction:  ");
    while (ptr->next != (*head))
    {
        printf("(%u) %u %d %u->",ptr,ptr->prev, ptr->data,ptr->next);
        ptr = ptr->next;
    }
    printf("(%u) %u %d %u\n",ptr,ptr->prev, ptr->data,ptr->next);
    printf("in backward direction:  ");
    while (ptr != (*head))
    {
        printf("(%u) %u %d %u->",ptr,ptr->prev, ptr->data,ptr->next);
        ptr = ptr->prev;
    }
    printf("(%u) %u %d %u\n",ptr,ptr->prev, ptr->data,ptr->next);
}
int main()
{
    int ch;
    struct node *head = NULL;
    do
    {
        printf("\nenter\n 1 to insert in begining\n 2 to insert at the end\n 3 to delete a specific element\n 5 to display\n 6 to exit\n 7 to insert after \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_begining(&head);
            break;
        case 2:
            insert_end(&head);
            break;
        case 3:
            delete_node(&head);
            break;
        case 5:
            display(&head);
            break;
        case 6:
            exit(1);
        case 7:
            insert_after(&head);
            break;

        default:
            printf("wrong choice");
        }
    } while (1);

    return 0;
}
