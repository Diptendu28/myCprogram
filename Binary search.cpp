/*BINARY SEARCH*/
#include<stdio.h>
int main()
{
	int a[20],i,n,low,high,mid,key,flag=0;
	printf("enter the size of the array");
	scanf("%d",&n);
	for(i=0;i<20;i++)
	{
		printf("enter the elements of the array");
		scanf("%d",&a[i]);
	}
	printf("enter the key element");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			flag=1;
			break;
		}
		else if(a[mid]>key)
		{
			high=mid-1;
		}
		else
			low=mid+1;
	}
	if(flag==1)
		printf("element %d found at position %d ",key,mid);
	else
		printf("element %d not found",key);
}
