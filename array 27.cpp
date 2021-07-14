/*Upper Diagonal And Lower Diagonal Of a Matrix of a Principal Diagonal*/
#include <stdio.h>
#include<stdlib.h>
int main()
{
 	int i,j,r,c,a[10][10];
    printf("Enter the r and c value:");
 	scanf("%d%d",&r,&c);
 	printf("\nPlease enter the elements of the matrix.");
 	printf("\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
 	printf("Matrix is:\n");
 	for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    if(r!=c)
    {
        printf("The matrix is not square matrix.");
        exit(0);
	}
	printf("\nThe upper diagonal of this matrix with respect to principal diagonal is-");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j&&i!=r-1)
			{
				printf("%d",a[i][j+1]);
				if(i!=r-2)
				{
					printf(",");
				}
			}
		}
	}
	printf("\nThe lower diagonal of this matrix with respect to principal diagonal is-");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j&&i!=0)
			{
				printf("%d",a[i][j-1]);
				if(i!=r-1)
				{
					printf(",");
				}
			}
		}
	}
	return 0;
}
    
