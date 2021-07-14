/* 1 +(1*1) + 2 + (1*2) + 3 + (1*2*3) + 4 + (1*2*3*4) +..... n terms */
#include<stdio.h>
int main()
{
	int n,i,sum=0,fact=1;
	printf("enter a number ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
		sum=sum+i+fact;
	}
	printf("sum of the series =%d",sum);
	return 0;	
}
