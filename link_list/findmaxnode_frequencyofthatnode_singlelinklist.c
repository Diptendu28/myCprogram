/*create a single link list and find the maximum node and then find the frequency of that maximum node*/
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
    printf("enter no. of nodes: \n");
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

int maximum(struct node *head)
{
    struct node *ptr;
    int max;
    max=head->data;
    ptr=head->link;

    while(ptr!=0)
    {
        if(ptr->data > max)
        {
            max= ptr->data;
        }
        ptr= ptr->link;
    }
    printf("\nthe maximum node value is %d\n",max);
    return max;
}

 void freq(struct node *head,  int max)
{
    struct node *ptr;
    ptr=head;
    int count=0;

    while(ptr!=0)
    {
        if(ptr->data == max)
        {
            count++;
        }
        ptr= ptr->link;
    }
    printf("the frequency of the maximum node: %d \n",count);
}

int main()
{
    int ch;
    printf("Enter elements to create a linked list\n");
    create();
   	display();
   	freq(head,maximum(head));
	return 0;
}
