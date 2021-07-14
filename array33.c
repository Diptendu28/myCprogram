#include<stdio.h>
int main()
{
	int a,b,m[10][10],n[10][10],i,j,sum[20][20];
	printf("enter the no of rows");
	scanf("%d",&a);
	printf("enter the number of col");
	scanf("%d",&b);
	printf("enter the element of 1st matrix");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("enter the element of 2nd matrix");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d",&n[i][j]);
			printf("%d\t",n[i][j]);
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%d\t",n[i][j]);
		}
		printf("\n");
	}
	printf("final matrix is:\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			sum[i][j]=m[i][j]+n[i][j];
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	return 0;
}
