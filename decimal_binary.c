#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void push(int x,int *top,int stack_arr[])
{
    if(*top==(MAX-1))
        printf("Stack Overflow\n");
    else
    {
        *top=*top+1;
        stack_arr[*top] = x;
    }
}
void DecToBin(int num)
{
    int stack[MAX],top=-1,rem;
    while(num!=0)
    {
        rem=num%2;
        push(rem,&top,stack);
        num/=2;
    }
    while(top!=-1)
        printf("%d",pop(&top,stack));
    printf("\n");
}

int pop(int *top, int stack_arr[])
{
    int x;
    if(*top==-1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        x = stack_arr[*top];
        *top=*top-1;
    }
    return x;
}
int main()
{
    int num;
    printf("Enter an integer : ");
    scanf("%d",&num);
    printf("Binary Equivalent is : ");
    DecToBin(num);
 	return 0;
}
 

