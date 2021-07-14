/*polynomial addition*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,*b,*c,i,j,k,ct=0;
	printf("Enter the order of 1st polynomial: ");
	scanf("%d",&j);
	a=(int*)malloc(j*sizeof(int));
	for(i=0;i<=j;i++)
	{
		printf("Enter the co-efficient of x^%d: ",i);
		scanf("%d",&a[i]);
	}
	printf("enter the order of 2nd polynoimal: ");
	scanf("%d",&k);
	b=(int*)malloc(k*sizeof(int));
	for(i=0;i<=k;i++)
	{
		printf("Enter the co-efficient of x^%d: ",i);
		scanf("%d",&b[i]);
	}
	if(j>=k)
	{
		c=(int*)malloc(j*sizeof(int));
		for(i=0;i<=j;i++)
		{
			c[i]=a[i]+b[i];
			ct++;
		}
	}
	else
	{
		c=(int*)malloc(k*sizeof(int));
		for(i=0;i<=k;i++)
		{
			c[i]=a[i]+b[i];
			ct++;
		}
	}
	printf("The first polynomial is: ");
	for(i=j;i>0;i--)
		printf("%dx^%d+",a[i],i);
	printf("%d\n",a[i]);
	printf("The second polynomial is: ");
	for(i=k;i>0;i--)
		printf("%dx^%d+",b[i],i);
	printf("%d\n",b[i]);
	printf("Added polynomial: ");
	for(i=ct-1;i>0;i--)
		printf("%dx^%d+",c[i],i);
	printf("%d",c[i]);
	return 0;
}
