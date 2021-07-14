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
        ptr->prev = NULL;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
        ptr->prev = NULL;
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
        insert_begining(head);
        return;
    }
    cptr = *head;
    while (cptr->next != NULL)
        cptr = cptr->next;
    cptr->next = ptr;
    ptr->prev = cptr;
    ptr->next = NULL;
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
    while (cptr->next != NULL)
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
    	ptr->next = NULL;
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
//    ptr =*head;
    if (*head == NULL)
    {
        printf("Nothing to delete");
        return;
    }
    printf("\nenter the node to be deleted:");
    scanf("%d", &item);
    if((*head)->data==item)
    {
        if((*head)->next==NULL)
        {
        	(*head)->prev=NULL;
        	(*head)=NULL;
//        	free(ptr);
			free(*head);
        	printf("element deleted!!\n");
        	return;
		}
		(*head)=(*head)->next;
        (*head)->prev=NULL;
        return;
    }
    cptr=(*head)->next;
    while (cptr->next != NULL)
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
        cptr->prev->next=NULL;
        cptr->prev=NULL;
        free(cptr);
        return;
    }
    printf("element not found");
}
void reverse(struct node **head)
{
    struct node *ptr, *tptr;
    if(*head==NULL||(*head)->next==NULL)
    	return;
    ptr = *head;
    while (ptr->next!= NULL)
    {
        tptr = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next=tptr;
        ptr=ptr->prev;
    }
    ptr->next=ptr->prev;
    ptr->prev=NULL;
    *head=ptr;
}

void display(struct node **head)
{
    struct node *ptr;
    if(*head==NULL)
    {
        printf("Empty link list!!\n");
        return;
    }
    ptr = *head;
    printf("in forward direction:  ");
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
    printf("in backward direction:  ");
    while (ptr->prev != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d\n", ptr->data);
}
int main()
{
    int ch;
    struct node *head = NULL;
    do
    {
        printf("\nenter\n 1 to insert in begining\n 2 to insert at the end\n 3 to delete a specific element\n 4 to reverse\n 5 to display\n 6 to exit\n 7 to insert after \n");
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
        case 4:
            reverse(&head);
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
