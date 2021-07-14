#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	printf("enter no of plot");
	scanf("%d",&n);
	float a[n],b[n],p[n],x[n];
	float s,big=0;
	for(i=0;i<n;i++)
	{
		printf("enter side a");
		scanf("%f",&a[i]);
		printf("enter side b");
		scanf("%f",&b[i]);
		printf("enter the angle between them");
		scanf("%f",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		s=0.5*a[i]*b[i]*sin(p[i]);
		x[i]=s;
	}
	big=x[0];
	for(i=1;i<n;i++)
	{
		if(x[i]>big)
		big=x[i];
	}
	printf("the largest area is %.2f",big);
}
