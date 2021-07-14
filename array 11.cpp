/* Saddle point of a matrix */
#include<stdio.h>
int main()
{
	int a[4][4],i,j,k,small=0,x=0,y=0;
	printf("\nenter the elements of the array");
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<4;i++)
	{
		int big=a[i][0];
		for(j=0;j<4;j++)
		{
			if(big<a[i][j])
			{
				big=a[i][j];
				x=i;
				y=j;
			}
		}
		printf("\nbiggest %d, row=%d, col=%d  ",big,x,y);
		small=1;
		for(k=0;k<4;k++)
		{
			if(big>a[k][y])
			{
				small=0;
				printf("\nNo Saddle");
				
			}
		}
		if(small==1)
		{
			printf("\nsaddle point value is %d",a[x][y]);
			printf("\nrow is %d",x);
			printf("\ncolumn is %d",y);
		}
		else
		printf("no saddle point");
	}
}
