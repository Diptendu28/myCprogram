/*Delete duplicate element*/
#include<stdio.h>
int main()
{
	int n,k,count;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the number of elements: ");
	for(k=0;k<n;k++)
	{
		printf("\n Array[%d]=",k);
		scanf("%d",&a[k]);
	}
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j+1]<a[j])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			else
				break;
		}
	}
	for (i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
    		if(a[i] == a[j])
    		{
    			for(k = j; k < n; k++)
    			{
    				a[k] = a[k + 1];
				}
				n--;
				j--;
			}
		}
	}
	printf("\n Final Array after Deleteing Duplicate Array Elements is:\n");
 	for (i = 0; i < n; i++)
  	{
 		printf("%d\t", a[i]);
  	}	     
}

