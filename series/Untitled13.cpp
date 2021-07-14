/*1!+2!+3!+4!+.....n!terms*/
#include<stdio.h>
int main()
{
	int i=1,fact=1,sum=0,n;
	printf("enter value of n");
	scanf("%d",&n);
	for(;i<=n;i++)
	{
		fact=fact*i;
		sum=sum+fact;
	}
	printf("sum=%d",sum);
	return 0;
}
