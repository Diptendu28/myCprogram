/*link_list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head;
void create_node(int n)
{
	struct node *temp, *nw;
	int no,i;
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
	while(temp!=NULL)
	{
		printf("%5d",temp->data);
		temp = temp->link;
	}
}
//void insertion_begin()
//{
//	struct node *ptr;
//	ptr=(struct node*)malloc(sizeof(struct node));
//	printf("enter data");
//	scanf("%d",&ptr->data);
//	if(head==NULL)
//	{
//		head=ptr;
//		ptr->link=NULL;
//	}
//	else
//	{
//		ptr->link=head;
//		head=ptr;
//	}
//}
//void insertion_end()
//{
//	struct node *ptr,*cptr;
//	cptr=(struct node*)malloc(sizeof(struct node));
//	printf()
//}
void main()
{
	int n;
	printf("\n Enter the number of nodes : ");
	scanf("%d",&n);
	create_node(n);
	printf("\n Data entered : ");
	display();
}



