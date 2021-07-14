/*  1
	4 16
	9 25 49  */
#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("enter number of rows:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=1;j<=i;j++)
		{
			printf("%d ",k*k);
			k=k+2;
		}
		printf("\n");
	}
}
