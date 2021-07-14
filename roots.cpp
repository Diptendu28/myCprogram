#include<stdio.h>
#include<math.h>
int main()
{
	float x1,x2,d,b,a,c,r,y;
	printf("Enter the value:");
	scanf("%f",&a);
	printf("Enter the value:");
	scanf("%f",&b);
	printf("Enter the value:");
	scanf("%f",&c);
	
	d=pow(b,2)-4*a*c;
	x1=(-b+sqrt(d))/2*a;
	x2=(-b-sqrt(d))/2*a;
	
	if(d>0)
	{
		printf("%f and %f are the real and unequal roots",x1,x2);
		
	}
	else
	{
		if(d==0)
		{
			printf("%f and %f are the real and equal roots",x1,x2);
		}
		else
		{
			d=-d;
			r=-b/2*a;
			y=sqrt(d)/2*a;
			printf("%f+(i*%f) the imaginary roots",r,y);
			printf("%f-(i*%f) the imaginary roots",r,y);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;	
}
