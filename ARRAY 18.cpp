/*UPPER TRAINGULAR MATRIX SEARCH*/
#include<stdio.h>
int main()
{
	int i,j,m,n,a[5][5],flag=0;
	printf("\nenter row and col:\n");
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nenter %d row %d col:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i][i-j-1]!=0)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	{
		printf("\nNot upper traingular matrix");
	}
	else
	{
		printf("\nUpper traingular matrix");
	}
}
