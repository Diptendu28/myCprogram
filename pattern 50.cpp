/* 	1
	2 4
	3 9 27
	4 16 64 256   */
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
			printf("%d ",k);
			k=k*i;
		}
		printf("\n");
	}
}
