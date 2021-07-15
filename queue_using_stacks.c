/*C Program to Implement Queues using Stacks*/
#include <stdio.h>
#include <stdlib.h>
int push(int val,int N,int *stack,int *top)
{
	if(*top==N-1)
		printf("\nQueue is full.\n");
	else
	{
		(*top)++;
		stack[*top]=val;
	}
}
int pop(int *stack,int *top)
{
	return stack[(*top)--];
}
int enqueue(int val,int n,int *stack,int *top)
{
//	count=0;
//	while(count<n)
//	{
//		printf("Enter the value : ");
//		scanf("%d",&val);
		push(val,n,stack,top);
		printf("element is inserted");
//		count++;
//	}
}

int dequeue(int n,int *stack1,int *stack2,int *top1,int *top2)
{
	int i,a,c=*top1;
	for(i=0;i<=c;i++)
		push(pop(stack1,top1),n,stack2,top2);
	pop(stack2,top2);
	c--;
	if(*top2==-1)
		printf("\nQueue is empty...\n");
	else
		printf("\nThe front element is dequeued.\n"); 
	for(i=0;i<=c;i++)
		push(pop(stack2,top2),n,stack1,top1);
}

void display(int *stack1,int top1)
{
	int i;
	if(top1==-1)
		printf("\nQueue is empty...\n");
	else
	{
		printf("\nThe Queue is : ");
		for(i=0;i<=top1;i++)
			printf("%d\t",stack1[i]);
		printf("\n");
	}
}

int main()
{
	int ch,val,n,a,top1=-1,top2=-1;
	int *stack1,*stack2;
	printf("\nEnter the number of elements in queue : ");
	scanf("%d",&n);
	stack1=(int*)malloc(sizeof(int)*n);
	stack2=(int*)malloc(sizeof(int)*n);
	do
	{
		printf("\nPress 1 to Enqueue element into queue\nPress 2 to Dequeue element from queue\nPress 3 Display from queue\nPress 0 to exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: printf("enter data");
			        scanf("%d",&val);
					enqueue(val,n,stack1,&top1);
					break;
			case 2: dequeue(n,stack1,stack2,&top1,&top2);
					//printf("\nThe dequeued element is : %d.\n",a);
					break;
			case 3: display(stack1,top1);
					break;
			case 4:	printf("\nExit....\n");
					break;
			default:printf("Wrong choice....Please try again!!!!");
		}
	}
	while(ch!=0);
	return 0;
}
