/*Lower Traingular Matrix and Upper Traingular Matrix*/
#include <stdio.h>
int main()
{
 
        int i,j,r,c,array[10][10];
        printf("Enter the r and c value:");
 		scanf("%d%d",&r,&c);
 		printf("\nPlease enter the elements of the matrix.");
 		printf("\n");
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("array[%d][%d] = ", i, j);
                scanf("%d", &array[i][j]);
            }
        }
        printf("\n");
 		printf("Matrix is:\n");
 		for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%d\t", array[i][j]);
            }
            printf("\n");
        }
        printf("\nThe Lower Traingular matrix is-");
 		for (i = 0; i < r; i++)
        {
            printf("\n");
            for (j = 0; j < c; j++)
            {
                if (i >= j)
                {
                    printf("%d ", array[i][j]);
                }
                else
                {
                    printf("\t");
                }
            }
 		}
 		printf("\nThe Upper traingular Matrix is-");
        for (i = 0; i < r; i++)
        {
            printf("\n");
            for (j = 0; j <c; j++)
            {
	            
				if(i > j)
			    {
            		printf(" \t7");
           	
         		}
         		else
		 		{
            		printf("%d\t", array[i][j]);
		 		}
            	
           	}
        }
}

