/*input a matrix then transpose it and check whether it is symmetric or not*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,flag=1,m;
	int **a,**b;
	printf("enter the row of the array");
	scanf("%d",&m);
	printf("enter the col of the array");
	scanf("%d",&n);
	a=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
		a[i]=(int*)malloc(n*sizeof(int));
	b=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		b[i]=(int*)malloc(m*sizeof(int));
	printf("enter the elements of the array");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("original matrix is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			b[j][i]=a[i][j];
	}
	printf("transpose matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	if(m!=n)
	{
		printf("matrix is not symmetric");
		exit(0);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=b[i][j])
				flag=0;
		}
	}
	if(flag)
		printf("matrix is symmetric");
	else
		printf("matrix is not symmetric");
	for(i=0;i<m;i++)
	{
		free(a[i]);
	}
	free(a);
	for(i=0;i<n;i++)
	{
		free(b[i]);
	}
	free(b);
	return 0;
}

