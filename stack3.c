/*postfix evaluation*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}
int pop()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}
void postfix_evaluation(char *str)
{
	int i,x,y;
	for(i=0;str[i]!='\0';i++)
	{
		switch(str[i])
		{
			case'+':
				x=pop();
				y=pop();
				push(y+x);
				break;
			case'-':
				x=pop();
				y=pop();
				push(y-x);
				break;
			case'*':
				x=pop();
				y=pop();
				push(y*x);
				break;
			case'/':
				x=pop();
				y=pop();
				push(y/x);
				break;
			case '^':
				x=pop();
				y=pop();
				push(pow(y,x));
				break;
			default:
				push(str[i]-48);
		}
	}
	printf("result is %d\n",stack[top]);
}
int main()
{
	int x,y;
	char str[30];
	printf("enter postfix expression: ");
	gets(str);
	postfix_evaluation(str);
	return 0;
}
