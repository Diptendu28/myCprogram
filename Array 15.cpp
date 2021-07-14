/* VERTICAL FLIP OF A MATRIX*/
#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of the array");
	scanf("%d",&n);
	int  a[n][n],i,j=0,temp=0;
	printf("enter the elements of the array");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("original matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
			printf("\n");
	}
	for(i=0;i<=n/2;i++)
	{
		for(j=i;j<n;j++)
		{
			temp=a[i][j];
			a[i][j]=a[n-i-1][j];
			a[n-i-1][j]=temp;
		}
	}
	printf("vertical flip matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}

