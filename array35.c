/*Input a matrix and print the upper triangular matrix and lower triangular matrix*/
#include<stdio.h>
#include<stdlib.h>
int main() 
{
   int m,n,r,c;
   int **a;
   printf("Please enter the number of rows for the matrix: ");
   scanf("%d",&m);
   printf("Please enter the number of columns for the matrix: ");
   scanf("%d",&n);
   printf("\n");
   if(m!=n)
	{
   		printf("matrix format is wrong.\n");
   		printf("please give a correct form.");
   		exit(0);
	}
    a=(int*)malloc(m*sizeof(int));
	for(r=0;r<m;r++)
		a[r]=(int*)malloc(n*sizeof(int));
   printf("Please enter the elements for the Matrix: \n");
   for(r=0;r<m;r++)
   {
      for(c=0;c<n;c++)
	  {
         scanf("%d",&a[r][c]);
      }
   }
   printf("the original matrix is\n");
   for(r=0;r<m;r++)
   {
      printf("\n");
	  for(c=0;c<n;c++)
	  {
        printf("%d\t",a[r][c]);
      }
      printf("\n");
   }
   printf("\n The Lower Triangular Matrix is: \n");
   for(r=0;r<m;r++)
   {
      for(c=0;c<n;c++)
	  {
	  	if(r>=c)
         	printf("%d\t",a[r][c]);
      	else
	  	{
         	printf("0");
         	printf("\t");
      	}
   	  }
   	  printf("\n");
   }
   printf("\n\n The Upper Triangular Matrix is: \n");
   for(r = 0;r<m;r++)
   {
      for(c=0;c<n;c++)
	  {
         if(r>c)
		 {
            printf("0");
            printf("\t");
         }
         else
            printf("%d\t",a[r][c]);
	  }
	  printf("\n");
   }
   return 0;
}
