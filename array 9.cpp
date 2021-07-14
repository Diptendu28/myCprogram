/*Input 2 arrays of size 10.Sort them.Copy the elements from both the arrays in a third  array in sorted order */
#include<stdio.h>
int main()
{
	int a[10],b[10],c[20],i,j,temp;
	printf("enter the elements of 1st array");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	
	printf("enter the elements of 2nd array");
	for(i=0;i<10;i++)
		scanf("%d",&b[i]);
	for(i=0;i<10;i++)
	{
		for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
	}
	for(i=0;i<10;i++)
		printf(" %d",a[i]);
	printf("\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
			if(b[j]>b[j+1])
			{
			temp=b[j];
			b[j]=b[j+1];
			b[j+1]=temp;
			}
	}
	for(i=0;i<10;i++)
		printf(" %d",b[i]);
	printf("\n");
	int p=0,q=0;
	i=0;
	while(p<10&&q<10)
	{
		if(a[p]<b[q])
			c[i++]=a[p++];
		else
			c[i++]=b[q++];
	}
	if(p<10)
		for(j=p;j<10;j++)
			c[i++]=a[j];
	if(q<10)
		for(j=q;j<10;j++)
			c[i++]=b[j];
	printf("\nresult:\n");
	for(i=0;i<20;i++)
		printf(" %d",c[i]);
}
