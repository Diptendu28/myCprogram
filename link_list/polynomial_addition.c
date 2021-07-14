/*polynomial addition*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node *link;
};
struct node *sorted_insertion(struct node *head, int coeff,int exp)
{
	struct node *ptr,*cptr;
	cptr=(struct node*)malloc(sizeof(struct node));
	cptr->coeff=coeff;
	cptr->exp=exp;
	if(head==NULL||head->exp>=cptr->exp)
	{
		cptr->link=head;
		head=cptr;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL&&ptr->link->exp<cptr->exp)
		{
			ptr=ptr->link;
		}
		cptr->link=ptr->link;
		ptr->link=cptr;
	}
	return head;
}
struct node *create(struct node*head)
{
	int i,exp,coeff,n;
	printf("\nEnter no of terms:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter coefficient and exponent:");
		scanf("%d%d",&coeff,&exp);
		head=sorted_insertion(head,coeff,exp);
	}
	return head;
}
void display(struct node*head)
{
	struct node* ptr;
	ptr=head;
	while(ptr->link!=NULL)
	{
		printf("%dX^%d +",ptr->coeff,ptr->exp);
		ptr=ptr->link;
	}
	printf("%dX^%d",ptr->coeff,ptr->exp);
}
void add(struct node *p1,struct node*p2)
{
	struct node* start=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->exp>p2->exp)
		{
			start=sorted_insertion(start,p1->coeff,p1->exp);
			p1=p1->link;
		}
		else if(p2->exp>p1->exp)
		{
			start=sorted_insertion(start,p2->coeff,p2->exp);
			p2=p2->link;
		}
		else if(p1->exp==p2->exp)
		{
			start=sorted_insertion(start,p1->coeff+p2->coeff,p1->exp);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		start=sorted_insertion(start,p1->coeff,p1->exp);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		start=sorted_insertion(start,p2->coeff,p2->exp);
		p2=p2->link;
	}
	printf("\nresultant polynomial is:");
	display(start);
}
void main()
{
	struct node* p1=NULL;
	struct node* p2=NULL;
	printf("\nEnter data for first polynomial:\n");
	p1=create(p1);
	display(p1);
	printf("\nEnter data for second polynomial:\n");
	p2=create(p2);
	display(p2);
	add(p1,p2);
}

