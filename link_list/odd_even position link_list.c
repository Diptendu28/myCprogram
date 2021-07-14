#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* head3=NULL;
void create(struct node** head)
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
    *head = ptr;
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
void insert()
{
    struct node *ptr1,*ptr2,*ptr3,*cptr3;
    int i=2;
    ptr1=head1;
    ptr2=head2;
    ptr3=(struct node*)malloc(sizeof(struct node));
    ptr3->data=ptr1->data;
    ptr1=ptr1->link;
    head3=ptr3;
	while(ptr1!=NULL)
    {
        if(i%2!=0)
        {
        	cptr3=(struct node*)malloc(sizeof(struct node));
        	cptr3->data=ptr1->data;
        	ptr3->link=cptr3;
        	ptr3=cptr3;
        }
        i++;
        ptr1=ptr1->link;
    }
    ptr3->link=NULL;
    i=1;
    ptr3=head3;
    while(ptr3->link!=NULL&&ptr2!=NULL)
    {
        if(i%2==0)
        {  
        	cptr3=(struct node*)malloc(sizeof(struct node));
        	cptr3->data=ptr2->data;
        	cptr3->link=ptr3->link;
        	ptr3->link=cptr3;
        	ptr3=cptr3->link;
        }
        i++;
        ptr2=ptr2->link;  
    }
    while(ptr2!=NULL)
    {
        if(i%2==0)
        {
            cptr3=(struct node*)malloc(sizeof(struct node));
            cptr3->data=ptr2->data;
            cptr3->link=ptr3->link;
            ptr3->link=cptr3;
            ptr3=cptr3;
        }
        i++;
        ptr2=ptr2->link;
    }
}
void display(struct node** head)
{
    struct node *ptr;
    ptr = *head;
    printf("\nlist:");
    while (ptr->link != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}
int main()
{
    create(&head1);
    create(&head2);
    insert();
    display(&head1);
    display(&head2);
    display(&head3);
    return 0;

}
