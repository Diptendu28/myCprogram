/* 9 10 11 12
   6 7 8
   4 5
   3  */
#include<stdio.h>
int main()
{
	int i,j,k,n,p;
	printf("enter no of rows");
	scanf("%d",&n);
	k=(n*(n-1))/2+3;
	for(i=n-1;i>=0;i--)
	{
		p=k;
		for(j=i;j>=0;j--)
		{
			printf("%d ",p++);
		}
		printf("\n");
		k=k-i;
	}
}
