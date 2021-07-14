/*Spiral character pattern */
#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("\nenter the size of the array");
	scanf("%d",&n);
	char w[n];
	printf("\nEnter the word:");
	scanf("%s",&w);
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>=i;j--)
		{
			printf("%c",w[j]);
		}
		for(k=1;k<=(2*i-1);k++)
		{
			printf("%c",w[i]);
		}
		for(j=i;j<n;j++)
		{
			if(j>0)
			printf("%c",w[j]);
		}
		printf("\n");
	}
	for(i=1;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			printf("%c",w[j]);
		}
		for(k=1;k<=(2*i-1);k++)
		{
			printf("%c",w[i]);
		}
		for(j=i;j<n;j++)
		{
			printf("%c",w[j]);
		}
		printf("\n");
	}
}
