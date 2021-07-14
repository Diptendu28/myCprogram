/* binary search of a number by its position */
#include<stdio.h>
int main()
{
	int a[10],i,s,start,end,mid,f=0;
	for(i=0;i<10;i++)
	{
		printf("enter no");
		scanf("%d",&a[i]);
	}
	printf("enter no to search");
	scanf("%d",&s);
	start=0;
	end=9;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(s==a[mid])
		{
			printf("found at %d",mid);
			f=1;
			break;
		}
		if(s>a[mid])
		{
			start=mid+1;
		}
		if(s<a[mid])
		{
			end=mid-1;
		}
	}
	if(f==0)
	printf("\nnot found");
}
