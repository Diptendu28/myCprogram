/* stack implementation using two queue(using structure)*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
	int a[MAX];
	int front;
	int rear;
}q={{0},-1,-1},q1={{0},-1,-1};
int isfull()
{
    if((q.front==0&&q.rear==MAX-1)||(q.front==q.rear+1))
        return 1;
    else
        return 0;
}
int isempty()
{
    if(q.front==-1&&q.rear==-1)
    	return 1;
    else
        return 0;
}
void insertion(int item)
{
    if(isfull())
    {
        printf("\ninsertion not possible\n");
        return;
    }
    else
    {
    	if(q.front==-1&&q.rear==-1)
    		q.front=0;
    }
    q.rear=(q.rear+1)%MAX;
	q.a[q.rear]=item;
//    printf("\ninserted successfully.\n");
}
int deletion()
{
    int x,y;
	if(isempty())
    {
        printf("\nQueue is empty\n");
        return;
    }
//    y=queue[front];
//	printf("\ndeleted elemnet=%d",q.a[q.front]);
    if(q.front==q.rear)
    {
//    	printf("\ndeleted elemnet=%d",q.a[q.front]);
		q.front=-1;
    	q.rear=-1;
    	return q.a[x];
	}
	else
//		q.front++;
	{
		y=q.front;		
//		printf("\ndeleted elemnet=%d",q.a[q.front]);
		q.front=(q.front+1)%MAX;
		return q.a[y];
	}
}
//void peek()
//{
//    if(isempty())
//    {
//        printf("\nqueue is empty\n");
//        return;
//    }
//    printf("\nItem at the top is : %d\n",q.a[q.front]);
//}
int isfull1()
{
    if((q1.front==0&&q1.rear==MAX-1)||(q1.front==q1.rear+1))
        return 1;
    else
        return 0;
}
int isempty1()
{
    if(q1.front==-1&&q1.rear==-1)
    	return 1;
    else
        return 0;
}
void insertion1(int item)
{
    if(isfull1())
    {
        printf("\ninsertion not possible\n");
        return;
    }
    else
    {
    	if(q1.front==-1&&q1.rear==-1)
    		q1.front=0;
    }
    q1.rear=(q1.rear+1)%MAX;
	q1.a[q1.rear]=item;
}
int deletion1()
{
    int x,y;
	if(isempty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    if(q1.front==q1.rear)
    {
//    	printf("\ndeleted elemnet=%d",q.a[q.front]);
		x=q1.front;
		q1.front=-1;
    	q1.rear=-1;
    	return q1.a[x];
	}
	else
	{
		y=q1.front;		
//		printf("\ndeleted elemnet=%d",q.a[q.front]);
		q1.front=(q1.front+1)%MAX;
		return q1.a[y];
	}

}
void push(int item)
{
	int x;
	while(!isempty())
	{
		x=deletion();
		insertion1(x);
	}
	insertion(item);
	while(!isempty1())
	{
		insertion(deletion1());
	}
}
void pop()
{
	int x=deletion();
	if(x==-999)
		printf("stack underflow\n");
	else
		printf("popped element: %d\n",x);
}
void display()
{
    int i;
    if(isempty())
    {
        printf("\nnothing will be displayed\n");
        return;
    }
    else
	{
    	printf("\nstack elements :\n\n");
    	for(i=q.front;i!=q.rear;i=(i+1)%MAX)
        	printf("%d\n",q.a[i]);
    	printf("%d\n",q.a[q.rear]);
	}
}
void display1()
{
    int i;
    if(isempty1())
    {
        printf("\nnothing will be displayed\n");
        return;
    }
    else
	{
    	printf("\nstack elements :\n\n");
    	for(i=q1.front;i!=q1.rear;i=(i+1)%MAX)
        	printf("%d\n",q1.a[i]);
    	printf("%d\n",q1.a[q1.rear]);
	}
}
int main()
{
	int ch,x;
    do
    {
        printf("\n1.push\n");
    	printf("2.pop\n");
        printf("3.Display all stack elements\n");
        printf("4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1:
                    printf("\nEnter the item to be inserted : ");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                	display();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("\ninvalid input\n");
        }
    }
    while(1);
 	return 0;
}
