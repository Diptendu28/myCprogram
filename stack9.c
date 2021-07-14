/* double ended queue operation(using structure)*/
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
void insert_front(int item)
{
	if(isfull())
	{
		printf("queue overflow\n");
		return ;
	}
	if(q.front==-1&&q.rear==-1)
	{
		q.front=0;
		q.rear=0;
		q.a[q.front]=item;
	}
	else
	{
		q.front=(q.front-1+MAX)%MAX;
		q.a[q.front]=item;
	}
	
}
void insertion_rear(int item)
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
    printf("\ninserted successfully.\n");
}
void deletion_front()
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
void delete_rear()
{
	if(isempty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    if(q.front==q.rear)
    {
    	printf("\ndeleted elemnet=%d",q.a[q.rear]);
		q.front=-1;
    	q.rear=-1;
	}
	else
//		q.front++;
	{
		printf("\ndeleted elemnet=%d",q.a[q.rear]);
		q.rear=(q.rear-1+MAX)%MAX;
	}
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
//int main()
//{
//	int ch,x;
////    initia();
//    do
//    {
//        printf("\n1.insertion\n");
//    	printf("2.deletion\n");
//        printf("3.Display peek element\n");
//        printf("4.Display all queue elements\n");
//        printf("5.Quit\n");
//        printf("\nEnter your choice : ");
//        scanf("%d",&ch);
//        switch(ch)
//        {
//        	case 1:
//                    printf("\nEnter the item to be inserted : ");
//                    scanf("%d",&x);
//                    insertion_rear(x);
//                    break;
//            case 2:
//            		printf("\nenter the item to be insertes at front: ");
//            		scanf("%d",&x);
//					insert_front(x);
//            		break;
//            case 3:
//                    delete_rear();
//                    break;
//            case 4:
//            		deletion_front();
//            		break;
//            case 5:
//                    peek();
//                    break;
//            case 6:
//                	display();
//                    break;
//            case 7:
//                    exit(0);
//                    break;
//            default:
//                    printf("\ninvalid input\n");
//        }
//    }
//    while(1);
// 	return 0;
//}
int main()
{
    int ch,ch1,item;
//    init();
    do
    {
        printf("enter 1 for input restricted.\n");
		printf("enter 2 for output restricted.\n");
		printf("enter 3 for display.\n");
		printf("enter 4 for exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            		printf("enter 1 to insert from rear.\n");
					printf("enter 2 to delete from front.\n");
					printf("enter 3 to delete from rear.\n");
            		scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                		printf("enter item:");
                		scanf("%d",&item);
                		insertion_rear(item);
                		break;
                case 2:
                		deletion_front();
                		break;
                case 3:
//                		printf("enter item:");
//                		scanf("%d",&item);
//                		insertion_rear(item);
						delete_rear();
                		break;
            }
            break;
            case 2:
            		printf("enter 1 insert from front.\n");
					printf("enter 2 to insert from rear.\n");
					printf("enter 3 to delete from rear.\n");
            		scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                		printf("enter item:");
                		scanf("%d",&item);
						insert_front(item);
                		break;
                case 2:
                		printf("enter item:");
                		scanf("%d",&item);
                		insertion_rear(item);
                		break;
                case 3:
                		delete_rear();
                		break;
            }
            break;
            case 3:
            		display();
            		break;
            case 4:
            		exit(1);
            default:
            		printf("invalid input\n");
        }
    }
    while(1);
	return 0;
}
