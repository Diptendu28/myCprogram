/*c program to find the arithmetic mean,variance,standard deviation at any n values*/
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,mean=0,variance=0,diff;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("\n");
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the value of the %dth index:",i+1);
		scanf("%d",&a[i]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		mean+=a[i];
	}
	mean/=n;
	for(i=0;i<n;i++)
	{
		diff=(a[i]-mean);
		variance+=pow(diff,2);
	}
	variance/=n;
	float standard_deviation=pow(variance,0.5);
	printf("mean = %d\n",variance);
	printf("variance = %d\n",variance);
	printf("standard deviation = %f\n",standard_deviation);
	return 0;
}
