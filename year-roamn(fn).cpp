/* YEAR-ROMAN*/
#include<stdio.h>
int n;
int digit(int);
int digit(int n)
{
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	return i;
}
int main()
{
	int b,m,d,c,l,x,v,i;
	printf("enter a year");
	scanf("%d",&b);
	n=b/1000;
	if(n>0)
	{
		for(i=1;i<=n;i++)
		printf("m");
	}
	b=b%1000;
	n=b/500;
	if(n>0)
	{
		for(i=1;i<=n;i++)
		printf("d");
	}
	b=b%500;
	n=b/100;
	if(n>0)
	{
		for(i=1;i<=n;i++)
		printf("c");
	}
	b=b%100;
	n=b/50;
	if(n>0)
	{
		for(i=1;i<=n;i++)
		printf("l");
	}
	b=b%50;
	n=b/10;
	if(n>0)
	{
		for(i=1;i<=n;i++)
		printf("x");
	}
	b=b%10;
	if(b==9)
		printf("ix");
	else
	{
		n=b/5;
		if(n>0)
		{
		for(i=1;i<=n;i++)
			printf("v");
		}
		b=b%5;
		if(b==4)
			printf("iv");
		else
		{
			n=b/1;
			if(n>0)
			{
			for(i=1;i<=n;i++)
				printf("i");
			}
		}
	}
	return b;
}
