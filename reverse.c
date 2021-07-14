#include<stdio.h>
void print(int*,int);
void reversearray(int*,int);
void print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
}
void reversearray(int *p, int n)
{
	int *low,*high,temp;
	high=p+n-1;
	for(low=p;low<high;low++)
	{
		temp=*low;
		*low=*high;
		*high=temp;
		high--;
	}
}
int main()
{
	int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
    printf("Your enterd array is-");
	print(a,n);
	printf("\nReversed array is-");
	reversearray(a,n);
	print(a,n);
	return 0;
}
