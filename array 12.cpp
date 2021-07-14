/*Corner of matrix*/
#include<stdio.h>
int main()
{
	int m,n;
	printf("enter the number of rows: ");
	scanf("%d",&m);
	printf("enter the number of cols: ");
	scanf("%d",&n);
	int a[m][n],i,j;
	printf("enter the elements of the array: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("%d %d\n%d %d",a[0][0],a[0][n-1],a[m-1][0],a[m-1][n-1]);
}
