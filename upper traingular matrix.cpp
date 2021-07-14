/*Upper traingular matrix forming*/
#include<stdio.h>
int main() 
{
   int rows, cols, r, c, matrix[10][10];
   printf("Please enter the number of rows for the matrix: ");
   scanf("%d", &rows);
   printf("\n");
   printf("Please enter the number of columns for the matrix: ");
   scanf("%d", &cols);
   printf("\n");
   printf("Please enter the elements for the Matrix \n");
   printf("\n");
   for(r = 0; r < rows; r++)
   {
      for(c = 0;c < cols;c++)
	  {
         printf("element in [%d][%d] position: ",r,c);
		 scanf("%d", &matrix[r][c]);
      }
   }
   printf("The matrix is:\n");
   for(r=0;r<rows;r++)
   {
   		for(c=0;c<cols;c++)
   		{
   			printf("%d\t",matrix[r][c]);	
		}
		printf("\n");
   }
   printf("The Upper Triangular Matrix is:\n");
   for(r = 0; r < rows; r++)
   {
      printf("\n");
      for(c = 0; c < cols; c++)
	  {
         if(r > c)
		 {
            printf("0");
            printf("\t");
         }
         else
		 {
            printf("%d\t", matrix[r][c]);
		 }
      }
   }
}
