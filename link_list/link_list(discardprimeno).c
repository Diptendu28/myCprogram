#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data;
	struct node *link;
};
struct node *head;
void create_node(int n);
void display();
int is_prime();
void deletePnode();
void delete();
void main()
{

	int n;
	create_node(n);
	display();
	deletePnode();
	display();
}
void create_node(int n)
{
	struct node *temp, *nw;
	int no,i;
	printf("\n Enter the number of nodes : ");
	scanf("%d",&n);
	head = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter the data for node 1 : ");
	scanf("%d",&no);
	head->data = no;
	head->link = NULL;
	temp = head;
	for(i=2;i<=n;i++)
	{
		nw = (struct node*)malloc(sizeof(struct node));
		printf("\n Enter the data for %d node : ",i);
		scanf("%d",&no);
		nw->data = no;
		nw->link = NULL;
		temp->link = nw;
		temp = temp->link;
	}
}

void display()
{
	struct node *temp;
	if(head == NULL) 
	printf("\n No data");
	else
	temp = head;
	printf("\n Data entered : ");
	while(temp!=NULL)
	{
		printf("%5d",temp->data);
		temp = temp->link;
	}
}
int is_prime(int n)
{
	int i;
	if(n<=1)
		return 0;
	else
	{
		for(i=2;i<=n/2;i++)
		{
			if(n%i == 0)
			{
				return 0;
				break;
			}
		
		}
		return 1;
		
	}
	
}

void deletePnode()
{
	struct node *temp, *temp1;
	temp = head;
	while(temp!=NULL)
	{
		temp1 = temp->link;
		if(is_prime(temp->data))
			delete(temp->data);
		temp = temp1;
		
	}
	
}
void delete(int item)
{
	struct node *temp, *temp1;
	temp = head;
	while(temp->link!=NULL)
	{
		if(head->data == item)
		{
			temp1=head;
			head = head->link;
			free(temp1);
			return;
		}
		if(temp->link->data == item)
		{
			temp1 = temp->link;
			temp->link = temp1->link;
			free(temp1);
			return;
		}
		temp = temp->link;
	}
	printf("Element not found");
}

