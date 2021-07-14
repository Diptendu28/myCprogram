/*enter 2 different size array..copy them in a third array one after another*/
#include<stdio.h>
int input(int *pt)
{
	int i=0,size;
	printf("\nEnter no. of array elements: ");
scanf("%d",&size);
printf("\nEnter array elements:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&pt[i]);
	}
return size;
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
void copy(int *pt1,int n1,int *pt2,int n2,int *pt3)
{
	int i,j=0,n=0;
	for(i=0;i<n1+n2;i++)
	{
		if(i%2==0 && j<n1)
		{
			 pt3[i]=pt1[j++];
		}
		else if(n<n2)
		{
			pt3[i]=pt2[n++];
		}
	}
	printf("\n combined array");
}
int main()
{
int a[100],b[100],c[200],n1,n2;
	n1=input(a);
	 n2=input(b);
	display(a,n1);
	display(b,n2);
	copy(a,n1,b,n2,c);
	display(c,n1+n2);
}

