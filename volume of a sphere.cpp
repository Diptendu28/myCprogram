/* volume of a sphere*/
#include<stdio.h>
#include<math.h>
int main()
{
	float v=0,r=0;
	printf("\n enter the radius");
	scanf("%f",&r);
	v=1.3*3.14*pow(r,3);
	printf("\n the volume is %f" ,v);
	return 0;
}
