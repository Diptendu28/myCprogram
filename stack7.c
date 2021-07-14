/* circular queue operation(using structure)*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
	int a[MAX];
	int front;
	int rear;
}q={{0},-1,-1};

//void initia()
//{
//	q.front=-1;
//	q.rear=-1;
//}
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
    	{
    		q.front=0;
//    		q.rear=0;
//    		q.a[q.rear]=item;
		}
    }
    q.rear=(q.rear+1)%MAX;
	q.a[q.rear]=item;
    printf("\ninserted successfully.\n");
}
void deletion()
{
//    int y;
	if(isempty())
    {
        printf("\nQueue is empty\n");
        return;
    }
//    y=queue[front];
//	printf("\ndeleted elemnet=%d",q.a[q.front]);
    if(q.front==q.rear)
    {
    	printf("\ndeleted elemnet=%d",q.a[q.front]);
		q.front=-1;
    	q.rear=-1;
	}
	else
//		q.front++;
	{
		printf("\ndeleted elemnet=%d",q.a[q.front]);
		q.front=(q.front+1)%MAX;
	}
//	return y;
}
void peek()
{
    if(isempty())
    {
        printf("\nqueue is empty\n");
        return;
    }
    printf("\nItem at the top is : %d\n",q.a[q.front]);
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
    	printf("\nQueue elements :\n\n");
    	for(i=q.front;i!=q.rear;i=(i+1)%MAX)
        	printf("listed element: %d\n",q.a[i]);
    	printf("rear: %d\n",q.a[q.rear]);
//		printf("\n");
	}
}
int main()
{
	int ch,x;
//    initia();
    do
    {
        printf("\n1.insertion\n");
    	printf("2.deletion\n");
        printf("3.Display peek element\n");
        printf("4.Display all queue elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1:
                    printf("\nEnter the item to be inserted : ");
                    scanf("%d",&x);
                    insertion(x);
                    break;
            case 2:
                    deletion();
                    break;
            case 3:
                    peek();
                    break;
            case 4:
                	display();
                    break;
            case 5:
                    exit(0);
                    break;
            default:
                    printf("\ninvalid input\n");
        }
    }
    while(1);
 	return 0;
}
