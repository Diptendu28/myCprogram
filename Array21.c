/*lower traingular matrix*/
#include <stdio.h>
int main()
{
    int array[3][3];
    int row, col, isLower;
	printf("Enter elements in matrix of size %dx%d: \n", 3, 3);
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            scanf("%d",&array[row][col]);
        }
    }
	isLower=1;
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        
            if(col>row&&array[row][col]!=0)
            {
                isLower=0;
            }
        }
	if(isLower==1)
    {
        printf("\nMatrix is Lower triangular matrix: \n");
		for(row=0; row<3; row++)
        {
            for(col=0;col<3;col++)
            {
                printf("%d ",array[row][col]);
            }
			printf("\n");
        }
    }
    else
    {
        printf("\nMatrix is not a Lower triangular matrix");
        
    }
	return 0;
}
