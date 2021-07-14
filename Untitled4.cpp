/*Transpose of a matrix*/
#include<stdio.h>
int main()
{
	int a[4][4],i,j,temp;
	printf("enter the elements of the array");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
	}
	printf("original matrix is\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
	printf("transpose matrix is\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
}
