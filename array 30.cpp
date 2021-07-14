/*input an array print the highest square element of the highet number in that array*/
#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,i,j,t;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the number of elements: ");
	for(k=0;k<n;k++)
	{
		printf("\n Array[%d]=",k);
		scanf("%d",&a[k]);
	}
	printf("The array is: ");
	for(k=0;k<n;k++)
	{
		printf(" %d ",a[k]);
	}
	int b[n];
	int p=0;
	for(i=0;i<n;i++)
	{
		b[p]=pow(a[i],2);
		p++;
	}
	for(i=0;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(b[j+1]<b[j])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
			else
				break;
		}
	}
	printf("\nThe square of elements of sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\nThe largest element is: %d",b[i-1]);
	return 0;
}
