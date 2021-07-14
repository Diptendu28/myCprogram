/*Tridiagonal*/
#include<stdio.h>
int main()
{
	int i,j,k,m,n,count=0;
	printf("Enter the no of rows: ");
	scanf("%d",&m);
	printf("\nEnter the no of columns: ");
	scanf("%d",&n);
	int a[m][n];
	printf("\nEnter the elemnts of the array: \n\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Array[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("The matrix is:\n");	
	for(i=0;i<m;i++)
	{
		printf("\n");
		
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}	
	}
	printf("\nTridiagonal matrix:\n");
	printf("%d\t%d\n",a[0][0],a[0][1]);
	for(i=1;i<m-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i==j)
            {
				printf("%d\t%d\t%d",a[i][j-1],a[i][j],a[i][j+1]);
				break;
			}
			else
				continue;
        }
        printf("\n");
        printf("\t");
	}
 	if(i>=3)
 	{
	    count+=m-i;
    	for(k=0;k<count;k++)
			printf("\t");
 	}
	printf("%d\t%d\n",a[i][i-1],a[i][i]);
    return 0;
}

