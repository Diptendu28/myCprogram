/*input a string and reverse the string usinf stack*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull(int j)
{
    if(top==j-1)
        return 1;
    else
        return 0;
}
void pushChar(char *stack,char item,int j)
{
    if(isFull(j))
    {
        printf("Stack is FULL\n");
        return;
    }
    stack[++top]=item;
}
char popChar(char *stack)
{
	int item;
	if(isEmpty())
    {
        printf("Stack is EMPTY\n");
        return 0;
    }
    item=stack[top--];
    return item;
}
int main()
{
    int i,j;
	printf("enter the size of the reverse array\n");
    scanf("%d",&j);
	char *str,*stack;
    str=(char*)malloc((j+1)*sizeof(char));
    stack=(char*)malloc(j*sizeof(char));
    fflush(stdin);
    printf("Input a string: ");
    gets(str); 
    for(i=0;i<strlen(str);i++)
        pushChar(stack,str[i],j);
    for(i=0;i<strlen(str);i++)
        str[i]=popChar(stack);
	printf("Reversed String is: %s\n",str);
    return 0;
}

