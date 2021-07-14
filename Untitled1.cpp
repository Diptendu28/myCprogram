#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float s,area;
	printf("enter three sides of angle");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	s=(a+b+c)/2;
	area=s*(s-a)*(s-b)*(s-c);
	area=sqrt(area);
	printf("area is %f",area);
}
