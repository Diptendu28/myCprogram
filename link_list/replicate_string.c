/*Write a program to create a linked list containing string value. 
Then pass the linked list in a function which will replicate the nodes in the list by n times. 
The replicated nodes will be consecutive.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data[20];
    struct node *link;
};
void insert_end(struct node **head)
{
    struct node *ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%s",ptr->data);
    if(*head==NULL)
    {
        *head=ptr;
        ptr->link=NULL;
    }
    cptr=*head;
    while(cptr->link!=NULL)
    {
        cptr=cptr->link;
    }
    cptr->link=ptr;
    ptr->link=NULL;  
}

void replicate(struct node **head,int t)
{
    struct node *ptr=*head,*cptr;int i,j;
    if(*head == NULL)
    return;
    while(ptr!=NULL)
    {
        for(j=1;j<t;j++)
        {
            cptr=(struct node*)malloc(sizeof(struct node));  
            for(i=0;ptr->data[i]!='\0';i++)
            cptr->data[i]=ptr->data[i];
            cptr->data[i]='\0';
            cptr->link=ptr->link;
            ptr->link=cptr;
            ptr=cptr;
        }
        ptr=ptr->link;
    }
}
void display(struct node **head)
{
    struct node *ptr;
    ptr = *head;
    while (ptr->link != NULL)
    {
        printf("%s->", ptr->data);
        ptr = ptr->link;
    }
    printf("%s", ptr->data);
}
int main()
{
    int t,ch;struct node *head=NULL;
    while(1)
    {
        printf("\nenter 1 to enter data and -1 to exit:");
        scanf("%d",&ch);
        if(ch==1)
        insert_end(&head);
        else if(ch==-1)
        break;
        else
        {
            printf("wrong choice");
        }
    }
    printf("enter the no. of times you want to replicate");
    scanf("%d",&t);
    replicate(&head,t);
    display(&head);
    return 0;
}
