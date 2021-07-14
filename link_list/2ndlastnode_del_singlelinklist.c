/*write a program to delete the second last node from a single link list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void create()
{
    int n,i;
    struct node *ptr, *cptr;
    printf("enter no. of nodes:");
    scanf("%d", &n);
    if (n == 0)
        return;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &ptr->data);
    head = ptr;
    for (i = 2; i <= n; i++)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d", &cptr->data);
        ptr->link = cptr;
        ptr = cptr;
    }
    ptr->link=NULL;
}
//void insert_begining()
//{
//    struct node *ptr;
//    ptr=(struct node*)malloc(sizeof(struct node));
//    printf("enter data:");
//    scanf("%d",&ptr->data);
//    if(head==NULL)
//    {
//        head=ptr;
//        ptr->link=NULL;
//    }
//    else
//    {
//        ptr->link=head;
//        head=ptr;
//    }
//}
void delete_node()
{
    struct node *cptr=head,*ptr=head;
    if(head==NULL||head->link==NULL)
    {
        printf("Nothing to delete");
        return;
    }
    if(head->link->link==NULL)
    {
        head=ptr->link;
        ptr->link=NULL;
        printf("delted node is %d",ptr->data);
        free(ptr);
        return;
   	}
   	while(cptr->link->link!=NULL)
    {
        ptr=cptr;
        cptr=cptr->link;
    }
    ptr->link=cptr->link;
    printf("deleted node is %d",cptr->data);
    free(cptr);
}
void display()
{
    struct node *ptr;
    ptr = head;
    while (ptr->link != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}
int main()
{
    int ch;
    printf("Enter elements to create a linked list\n");
    create();
    do
    {
        printf("\n1 to delete second last element\n2 to display\n3 to exit\n  \n");
        scanf("%d",&ch);
        switch(ch)
        {
//            case 1:
//            insert_begining();
//            break;
            case 1:
            delete_node();
            break;
            case 2:
            display();
            break;
            case 3:
            exit(1);
            default:
            printf("wrong choice");
        }
    } while (1);
    return 0;
}
