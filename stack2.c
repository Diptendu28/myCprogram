/*stack operation*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
int isfull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
    	return 1;
    else
        return 0;
}
void push(int item)
{
    if(isfull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    stack[++top]=item;
    printf("\npushed successfully.\n");
}
void pop()
{
    if(isempty())
    {
        printf("\nStack Underflow\n");
        return;
    }
    printf("popped elemnet=%d",stack[top--]);
}
void peek()
{
    if(isempty())
    {
        printf("\nStack Underflow\n");
        return;
    }
    printf("\nItem at the top is : %d\n",stack[top]);
}
void display()
{
    int i;
    if(isempty())
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack elements :\n\n");
    for(i=top;i>=0;i--)
        printf(" %d\n",stack[i]);
    printf("\n");
}
int main()
{
    int ch,x;
    do
    {
        printf("\n1.Push\n");
    	printf("2.Pop\n");
        printf("3.Display peek element\n");
        printf("4.Display all stack elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1:
                    printf("\nEnter the item to be pushed : ");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2:
                    pop();
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
