#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of the matrix");
	scanf("%d",&n);
	printf("enter the elemnets of the array");
	int a[n][n],i,j,big=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(big<a[i][j])
		big=a[i][j];
	}
	printf("largest element of the matrix is %d",big);
}
