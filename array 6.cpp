/* if a square matrix is symmetric */
#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of the matrix");
	scanf("%d",&n);
	int a[n][n],i,j,count=0;
	printf("enter the elements of the array");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(a[i][j]==a[j][i])
		continue;
		else
		{
			count++;
			break;
		}
	}
	if(count==0)
	printf("matrix is symmetric");
	else
	printf("matrix is not symmmetric");
}
