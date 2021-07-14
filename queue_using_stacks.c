/*C Program to Implement Queues using Stacks*///pending

#include <stdio.h>
#include <stdlib.h>
#define N 100
int stack1[N],stack2[N];
int top1=-1,top2=-1;
int count=0;

int push1(int val)
{
	if(top1==N-1)
		printf("\nQueue is full.\n");
	else
	{
		top1++;
		stack1[top1] = val;
	}
}

int pop1()
{
	return stack1[top1--];
}

int push2(int val)
{
	stack2[++top2]=val;
}

int pop2()
{
	return stack2[top2--];
}

int enqueue(int val,int n)
{
	count=0;
	while(count<n)
	{
		printf("Enter the value : ");
		scanf("%d",&val);
		push1(val);
		count++;
	}
}

int dequeue()
{
	int i,a;
	for(i=0;i<=count;i++)
	{
		push2(pop1());
	}
	pop2();
	count--;
	if(top2==-1)
		printf("\nQueue is empty...\n");
	else
		printf("\nThe front element is dequeued.\n"); 
		
	for(i=0;i<=count;i++)
	{
		push1(pop2());
	}
}

void display()
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
	int ch,val,n,a;
	do
	{
		printf("\nPress 1 to Enqueue element into queue\nPress 2 to Dequeue element from queue\nPress 3 Display from queue\nPress 0 to exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: printf("\nEnter the number of elements in queue : ");
					scanf("%d",&n);
					count=0;
					if(n<N)
						enqueue(val,n);
					break;
			case 2: dequeue();
					//printf("\nThe dequeued element is : %d.\n",a);
					break;
			case 3: display();
					break;
			case 4:	printf("\nExit....\n");
					break;
			default:printf("Wrong choice....Please try again!!!!");
		}
	}
	while(ch!=0);
	return 0;
}
