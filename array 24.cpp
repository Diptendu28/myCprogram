/*Inserts and delete an element from an array*/
#include<stdio.h>
int main()
{
	int n,num;
	printf("\nenter the size of the array:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the value of %d th index:",i);
		scanf("%d",&a[i]);
	}
	printf("\nInput 1 to insert and 2 to delete an element from an index:");
	scanf("%d",&num);
	if(num==1)
	{
		int m,ind;
		printf("\nEnter the number you want to insert:");
		scanf("%d",&m);
		printf("\nEnter the position where you want to insert the value: ");
		scanf("%d",&ind);
		int b[n+1];
		for(int i=0;i<=n;i++)
		{
			if(i<ind)
				b[i]=a[i];
			else if(i==ind)
				b[i]=m;
			else
				b[i]=a[i-1];
		}
		printf("\nThe new array is:");
		for(int i=0;i<=n;i++)
		{
			printf("%d ",b[i]);		
		}
		printf("\n");
	}
	else if(num==2)
	{
		int ind;
		printf("\nEnter the index of the element where you want to delete:");
		scanf("%d",&ind);
		int b[n-1];
		for(int i=0;i<n-1;i++)
		{
			if(i<ind)
				b[i]=a[i];
			else if(i>=ind)
				b[i]=a[i+1];
		}
		printf("\nThe new array is:");
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	else
		printf("\nWrong input");
	return 0;
}
