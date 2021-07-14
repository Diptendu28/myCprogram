/*Tri-diagonal*/
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
	printf("%d\t%d\t%d\n",a[1][0],a[1][1],a[1][2]);
	for(i=2;i<=m-2;i++)
    {
    	for(k=1;k<i;k++)
			printf("\t"); 
        printf("%d\t%d\t%d",a[i][i-1],a[i][i],a[i][i+1]);
        printf("\n");
		 
 	}
 	for(k=1;k<i;k++)
		printf("\t");
 	printf("%d\t%d\n",a[i][i-1],a[i][i]);
    return 0;
}

