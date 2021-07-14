/*CHECKING AND PRINTING OF SPARSE MATRIX*/
#include<stdio.h>
#include<stdlib.h>
void three_tuple(int **b,int m,int n,int count)
{
	int x,**t,p=1,i,j;
	x=m*n-count;
	t=(int**)malloc((x+1)*sizeof(int*));
	for(i=0;i<x+1;i++)
		t[i]=(int*)malloc(3*sizeof(int));
	t[0][0]=m;
	t[0][1]=n;
	t[0][2]=x;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j]!=0)
			{
				t[p][0]=i;
				t[p][1]=j;
				t[p][2]=b[i][j];
				p++;
			}
		}
	}
	printf("representation of this sparse matrix in 3 tuple format\n");
	for(i=0;i<x+1;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",t[i][j]);
		printf("\n");
	}
}
int main()
{
	int i,j,count,m,n;
	int **a;
	printf("enter the size of the array");
	scanf("%d%d",&m,&n);
	a=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
		a[i]=(int*)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter elements of the array");
			scanf("%d",&a[i][j]);
		}
	}
	printf("original matrix is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			count++;
			else
			continue;
		}
	}
	if(count>0.5*(m*n))
	{
		printf("sparse matrix\n");
		three_tuple(a,m,n,count);
	}
	else
		printf("not sparse matrix");
	for(i=0;i<m;i++)
		free(a[i]);
	free(a);
	return 0;
}
