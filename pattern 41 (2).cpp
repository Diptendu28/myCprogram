#include<stdio.h>
int main()
{
	int i,j,k,n,s=1;
	printf("\nEnter the no of line:");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(k=1;k<=2*(n-i);k++)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("%d ",s++);
		}
		printf("\n");
	}
}
