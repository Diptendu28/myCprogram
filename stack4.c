/*queue operation*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 2
int queue[MAX];
int front=-1;
int rear=-1;
int isfull()
{
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(front==-1)
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
    	if(front==-1)
    		front=0;
    }
	queue[++rear]=item;
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
	printf("\ndeleted elemnet=%d",queue[front]);
    if(front==rear)
    {
    	front=-1;
    	rear=-1;
	}
	else
		front++;
//	return y;
}
void peek()
{
    if(isempty())
    {
        printf("\nqueue is empty\n");
        return;
    }
    printf("\nItem at the top is : %d\n",queue[front]);
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
    	for(i=front;i<=rear;i++)
        	printf(" %d\n",queue[i]);
    	printf("\n");
	}
}
int main()
{
    int ch,x;
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
