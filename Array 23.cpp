/*Product of matrix*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,m,n,p,q,x,y,k,sum=0;
	int A[10][10],B[15][20],C[20][20];
	printf("Enter the no of rows and columns of 1st matrix: ");
	scanf("%d %d",&m,&n);
	printf("\nEnter the no of rows and columns of 2nd matrix: ");
	scanf("%d %d",&p,&q);
	if(n==p)
		printf("\nProgram will run");
	else
	{
		printf("\nWrong input format!");
		exit(0);
	}
	printf("\nEnter the elemnts of the 1st matrix: \n\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Array[%d][%d]=",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("\nEnter the elemnts of the 2nd matrix: \n\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("Array[%d][%d]=",i,j);
			scanf("%d",&B[i][j]);
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			for(k=0;k<p;k++)
				sum=sum+A[i][k]*B[k][j];
			C[i][j]=sum;
			sum=0;
		}
	}
	printf("\nThe product of the two matrix is: ");
	for(i=0;i<m;i++)
		{
			printf("\n");
			for(j=0;j<q;j++)
			{
				printf("\t%d",C[i][j]);
			}
		}
	return 0;	
}	
