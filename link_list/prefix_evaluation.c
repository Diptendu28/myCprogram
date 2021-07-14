#include<stdio.h>
#include<math.h>
int stack[20];
int top=-1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void operation(int op1,int op2,char expression)
{
    int result;
    if(expression=='+')
    {
        result=op1+op2;
        push(result);
    }
    else if(expression=='-')
    {
        result=op1-op2;
        push(result);
    }
    else if(expression=='*')
    {
        result=op1*op2;
        push(result);
    }
    else if(expression=='/')
    {
        result=op1/op2;
        push(result);
    }
    else if(expression=='^')
    {
        result=pow(op1,op2);
        push(result);
    }
}

int main()
{
    char exp[20];
    int op1,op2,result;
    char *e;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    strrev(exp);
    e = exp;

    while(*e != '\0') //value at the address of the character array initially it is the address of first element of the array
    {


        if(isalnum(*e))
          push(*e-'0');
        else
          {
             op1=pop();
             op2=pop();
             operation(op1,op2,*e);
          }

        e++;
    }
    printf("%d",pop());
    return 0;

}
