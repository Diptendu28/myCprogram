/* volume of a cylinder*/
#include<stdio.h>
#include<math.h>
int main()
{
	float v=0,r=0,h=0;
	printf("\n enter the radius");
	scanf("%f",&r);
	printf("\n enter the height");
	scanf("%f",&h);
	v=3.141*pow(r,2)*h;
	printf("\n the volume is %f" ,v);
	return 0;
}
