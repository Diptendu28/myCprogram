/*Enter Two different size array.copy them in a third array one after another in a third array using pointer*/
#include<stdio.h>
void input(int *,int);
void display(int *,int);
void copy(int *,int *,int,int,int *);
void input(int *pt,int size)
{
	int i=0;
	printf("\nEnter array elements:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",pt+i);
	}
}
void display(int *pt,int size)
{
	int i=0,c=0;
	for(i=0;i<size;i++)
	{
if(i!=size-1)
		printf("%d,",pt[i]);
else
		printf("%d",pt[i]);
	}
	printf("\n");
}
void copy(int *pt1,int *pt2, int a, int b,int *c)
{
	int i,j=0,n=0;
	for(i=0;i<a+b;i++)
	{
		if(i%2==0 && j<a)
		{
			 c[i]=pt1[j++];
		}
		else if(n<b)
		{
			c[i]=pt2[n++];
		}
	}
	printf("\n combined array is-");
}
int main()
{
    int i,x,y,a[30],b[40],c[70];
	printf("enter the size of the 1st array");
	scanf("%d",&x);
	printf("enter the size of the 2nd array");
	scanf("%d",&y);
	input(a,x);
	input(b,y);
	display(a,x);
	display(b,y);
	copy(a,b,x,y,c);
	display(c,x+y);
}
