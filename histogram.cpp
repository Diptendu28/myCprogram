/*Histogram*/
#include<stdio.h>
int main()
{
	int a[20],b[20],c[10]={0},i,j,k,h=0,n,flag,count=0,temp;
	printf("enter no of elements");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<h;j++)
			if(b[j]==a[i])
			{
				flag=0;
				break;
			}
			if(flag)
			{
				count++;
				b[j]=a[i];
				for(k=0;k<n;k++)
					if(a[k]==b[j])
						c[h]++;
				h++;
			}
	}
	for(i=0;i<count-1;i++)
	
		for(j=0;j<count-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
		}	
	printf("\nELEMENTS\tHISTOGRAM");
	for(i=0;i<h;i++)
	{
		printf("\n%d\t\t",b[i]);
		for(j=0;j<c[i];j++)
			printf("*");
	}
}
