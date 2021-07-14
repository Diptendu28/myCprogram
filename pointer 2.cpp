/* input 10 numbers in a array using function.& call another function to print sum of the odd numbers*/
#include<stdio.h>
void input(int *pt)
{
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("enter a value");
		scanf("%d",pt);
		pt++;
	}
}
void sum(int *pt)
{
	int i=0,sum=0;
	for(i=0;i<10;i++)
	{
		
		if(*pt%2==1)
		sum=sum+*pt;
		pt++;
	}
	printf("Sum=%d",sum);
}
int main()
{
	int a[10];
	input(a);
	sum(a);
}


