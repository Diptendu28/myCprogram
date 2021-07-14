/*infix to prefix(callbyaddress)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
char pop(char *stack) 
{
	char a;
	a=stack[top];
	top--;
	return a;
}
void push(char symbol,char *stack) 
{
	top++;
	stack[top]=symbol;
}
int prcd(char symbol)  
{
	switch(symbol) 
	{
		case '+':
		        case '-':
		        return 2;
			break;
		case '*':
		        case '/':
		        return 4;
			break;
		case '$':
		        case '^':
		        return 6;
			break;
		case '#':
		        case '(':
		        case ')':
		        return 1;
			break;
	}
}
int isOperator(char symbol) 
{
	switch(symbol) 
	{
		case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        return 1;
			break;
		default:
		        return 0;
	}
}
char* reverse(char *array,int MAX) 
{
	int i,j;
	char *temp;
	temp=(char*)malloc(MAX+1*sizeof(char));
	for(i=strlen(array)-1,j=0;i+1!=0;--i,++j) 
	{
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return array;
}
void infixtoprefix(char *infix,char *prefix,char *stack,int MAX) 
{
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(infix,MAX);
	for (i=0;i<strlen(infix);i++) 
	{
		symbol=infix[i];
		if (isOperator(symbol)==0) 
		{
			prefix[j]=symbol;
			j++;
		}
		else 
		{
			if (symbol==')') 
			{
				push(symbol,stack);
			} 
			else if(symbol == '(') 
			{
				while (stack[top]!=')') 
				{
					prefix[j]=pop(stack);
					j++;
				}
				pop(stack);
			} 
			else 
			{
				if (prcd(stack[top])<=prcd(symbol)) 
				{
					push(symbol,stack);
				} 
				else 
				{
					while(prcd(stack[top])>=prcd(symbol)) 
					{
						prefix[j]=pop(stack);
						j++;
					}
					push(symbol,stack);
				}
			}
		}
	}
	while (stack[top]!='#') 
	{
		prefix[j]=pop(stack);
		j++;
	}
	prefix[j]='\0';
}
int main() 
{
	int MAX;
	printf("enter the size of the expression");
	scanf("%d",&MAX);
	fflush(stdin);
	char *infix,*prefix,temp;
	char *stack=(char*)malloc(MAX+1*(sizeof(char)));
	infix=(char*)malloc(MAX+1*sizeof(char));
	prefix=(char*)malloc(MAX+1*sizeof(char));
	printf("Enter infix operation: ");
	gets(infix);
	infixtoprefix(infix,prefix,stack,MAX);
	reverse(prefix,MAX);
	puts((prefix));
	return 0;
}
