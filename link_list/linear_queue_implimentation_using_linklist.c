#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the value you want to insert : ");
	scanf("%d",&x);
	ptr->data=x;
	ptr->next=NULL;
	
	if(front==NULL && rear==NULL)
	{
		front=rear=ptr;
		printf("\n The value %d is enqueued.\n",ptr->data);
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
		printf("\n The value %d is enqueued.\n",ptr->data);
	}
}

void dequeue()
{
	struct node *ptr;
	ptr=front;
	if(front==NULL && rear==NULL)
		printf("\n The Queue is Empty,nothing to dequeue.\n");
	else if(front==rear)
	{
		printf("\n The dequeued element is : %d\n",front->data);
		front=rear=NULL;
	}
	else
	{
		printf("\n The %d element is dequeued.\n",front->data);
		front=front->next;
		free(ptr);
	}
}

void display()
{
	struct node *ptr;
	if(front==NULL && rear==NULL)
		printf("\n The Queue is Empty,nothing to display.\n");
	else
	{
		ptr=front;
		printf("\n The Queue is : ");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void peek()
{
	if(front==NULL && rear==NULL)
		printf("\n The Queue is Empty.\n");
	else
		printf("\n The Peek is : %d\n",front->data);
}

int main()
{
	int ch,x;
	do
	{
		printf("\n\n ---Menu for Queue Operations---\n");
		printf("\n Press 1 for Enqueue\n Press 2 for Dequeue\n Press 3 to display the queue\n Press 4 to display the peek\n Press 0 to exit");
		printf("\n Enter your option : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	enqueue(x);
					break;
			case 2: dequeue();
					break;
			case 3:	display();
					break;
			case 4:	peek();
					break;
			case 0: printf("\n Exit...\n");
					break;
			default: printf("\n Wrong choice.... please try again...\n");
		}
	}
	while(ch!=0);
	return 0;
}
