/*INPUT 2 ARRAYS OF SIZE 10 .PRINT ALL THE COMMON ARRAY */
#include<stdio.h>
int main()
{
	int i,j,a[10],b[10],m,n;
	printf("enter the size of a and b : ");
	scanf("%d%d",&m,&n);
	printf("enter elemnets of 1st array : ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter elements of 2nd array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("common element is/are\n :");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		if(a[i]==b[j])
		{
			printf(" %d ",a[i]);
		}
	}
}
