/* REVERSE OF 10 NUMBERS USING ARRAY */
#include<stdio.h>
int main()
{
	int a[10],i,j,temp;
	printf("\nenter elements of array");
	for(i=0;i<10;i++)
	{
		printf("\nenter no");
		scanf("%d",&a[i]);
	}
	i=0;
	j=9;
	while(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
	printf("\nreverse array is \n");
	for(i=0;i<10;i++)
	printf("%d",a[i]);
}
