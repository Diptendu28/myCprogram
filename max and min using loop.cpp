/*  giving input a number and see which is maximum and minimum using loop*/
#include<stdio.h>
int main()
{
	int count=0,min=0,max=0,n=0,i;
	printf("\n enter a number");
	scanf("%d",&n);
	while(count!=n)
	{
		scanf("%d",&i);
		if(count==0)
		max=min=i;
		{
			if(i>max)
			max=i;
			if(i<min)
			min=i;
		}
		count++;
	}
	printf("\n %d is max and %d is min",max,min);
	
}
