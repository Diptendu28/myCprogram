/* REVERSE THE ARRAY */
#include<stdio.h>
void input(int *pt)
{
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("enter the elements of the array");
		scanf("%d",pt);
		pt++;
	}
}
void display(int *pt)
{
	int i=0;
	for(i<0;i<10;i++)
	{
		printf("%d\t",pt[i]);
	}
}
void reverse(int *pt)
{
	int i=0,j=9,temp=0;
	while(i<j)
	{
		temp=pt[i];
		pt[i]=pt[j];
		pt[j]=temp;
		i++;
		j--;
	}
}
int main()
{
	int a[10];
	input(a);
	reverse(a);
	display(a);
}
