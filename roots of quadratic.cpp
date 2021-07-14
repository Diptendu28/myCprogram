/* Roots of quadratic equation*/
#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,e,f,x,y;
	printf("enter the value");
	scanf("%f",&a);
	printf("enter the value");
	scanf("%f",&b);
	printf("enter the value");
	scanf("%f",&c);
	d=b*b-4*a*c;
	if(d<0)
	{
		d=-d;
		e=-b/(2*a);
		f=sqrt(d)/(2*a);
		printf("%f+(i*%f)\n",e,f);
		printf("%f-(i*%f)\n",e,f);
	}
	else
	{
		if(d==0)
		{
			printf("both roots are equal");
			x=-b/(2*a);
			printf("root is %f",x);
		}
		if(d>0)
		{
			printf("roots are real and distinct");
			x=(-b+sqrt(d))/(2*a);
			y=(-b-sqrt(d))/(2*a);
			printf("\nroots are:%f,%f",x,y);
		}
	}
}
