/*TRANSPOSE OF A MATRIX USING FUNCTION*/
#include<stdio.h>
int a[4][4];
void transpose()
{
	int i=0,j,temp;
	for(i=0;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
}
void display()
{
	int i=0,j=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
			
		}
		printf("\n");
	}
}
void input()
{
	int i=0,j=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
int main(void)
{
	printf(" enter the elements of the array\n");
	input();
	printf(" original array\n");
	display();
	transpose();
	printf(" array after transpose\n");
	display();
	return 0;
}
	


