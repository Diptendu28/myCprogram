/*infix to postfix(alternative method)*/
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 10
struct stack
{
    char s[MAX];
    int top;
};
struct stack st;
void push(char x)
{
	st.s[++st.top]=x;
}

char pop()
{
	return st.s[st.top--];
}
int precedence(char op)
{
	switch(op)
    {
        case '+':  return 1;
        case '-':  return 1;
        case '*': return 2;
        case '/': return 2;
        case '^':return 3;
        case '(':return 0;
    }
}
int main()
{
    char infix[100],postfix[100],ch;
    int i=0,j=0;
    printf("enter the infix expression\n");
    gets(infix);
    while((ch=infix[i++])!='\0')
    {
        if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while((ch=pop())!='(')
                postfix[j++]=ch;
        }
        else
        {
            while(precedence(st.s[st.top])>=precedence(ch))
                postfix[j++]=pop();
            push(ch);
        }
    }
    while(st.top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("the postfix expression=\n");
    puts(postfix);
    return 0;
}
