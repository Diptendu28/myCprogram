/*Linear queue operation(call by address)*/
#include<stdio.h>
#include<stdlib.h>
int isfull(int *rear,int max)
{
    if(*rear==max-1)
        return 1;
    else
        return 0;
}
int isempty(int *front)
{
    if(*front==-1)
    	return 1;
    else
        return 0;
}
void insertion(int *queue,int *front,int item,int *rear,int max)
{
    if(isfull(rear,max))
    {
        printf("\ninsertion not possible\n");
        return;
    }
    else
    {
    	if(*front==-1)
    		*front=0;
    }
	queue[++(*rear)]=item;
    printf("\ninserted successfully.\n");
}
void deletion(int *queue,int *front,int *rear)
{
	if(isempty(front))
    {
        printf("\nQueue is empty\n");
        return;
    }
//	printf("%d%d\n",*front,*rear);
	printf("\ndeleted elemnet is %d\n",queue[*front]);
    if(*front==*rear)
    {
    	*front=-1;
    	*rear=-1;
	}
	else
		(*front)++;
}
void peek(int *queue,int *front)
{
    if(isempty(front))
    {
        printf("\nqueue is empty\n");
        return;
    }
    printf("\nItem at the top is : %d\n",queue[*front]);
}
void display(int *queue,int *front,int *rear)
{
    int i;
    if(isempty(front))
    {
        printf("\nnothing will be displayed\n");
        return;
    }
    else
	{
    	printf("\nQueue elements :\n\n");
    	for(i=*front;i<=*rear;i++)
        	printf(" %d\n",queue[i]);
    	printf("\n");
	}
}
int main()
{
    int ch,x,front=-1,rear=-1,max;
    printf("enter the size of the array\n");
    scanf("%d",&max);
	int *queue;
    queue=(int*)malloc(max*sizeof(int));
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
					insertion(queue,&front,x,&rear,max);
                    break;
            case 2:
                    deletion(queue,&front,&rear);
                    break;
            case 3:
                    peek(queue,&front);
                    break;
            case 4:
                	display(queue,&front,&rear);
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
