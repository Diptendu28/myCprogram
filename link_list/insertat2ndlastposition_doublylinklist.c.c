/*create doubly link list and insert a node at 2nd last position*/
#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
	int data; 
    struct node *prev;  
    struct node *next;   
};  
void insert_begin(struct node**head)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	if(*head==NULL)
	{
		*head=temp;
		temp->prev=NULL;
		temp->next=NULL;
	}
	else
	{
		temp->next=*head;
		(*head)->prev=temp;
		*head=temp;
		temp->prev = NULL;
	}
}
void insert_secondlast(struct node**head)
{
	struct node *ptr,*temp;
	if(*head==NULL)
	{
		insert_begin(head);
		return;
	}
	ptr=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->prev->next=temp;
	temp->prev=ptr->prev;
	ptr->prev=temp;
	temp->next=ptr;
}
void display_forward(struct node**head)
{
	struct node*ptr;
	if(*head==NULL)
	{
		printf("Link list is empty");
		return;
	}
	ptr=*head;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
void display_backward(struct node**head)
{
	struct node*ptr;
	if(*head==NULL)
	{
		printf("Link list is empty");
		return;
	}
	ptr=*head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	while(ptr->prev!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->prev;
	}
	printf("%d\t",ptr->data);
}
int main()
{
	struct node *head=NULL;
	int ch,n;
	do
	{
		printf("\nenter 1 for insert_begin\nenter 2 to insert at 2nd last\nEnter 3 for display_forward\nenter 4 for display_backward\nenter 5 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert_begin(&head);
			break;
			break;
			case 2:
			insert_secondlast(&head);
			break;
			case 3:display_forward(&head);
			break;
			case 4:display_backward(&head);
			break;
			case 5:exit(0);
			break;
			default:printf("Invalid Input");
		}
	}
	while(1);
}
