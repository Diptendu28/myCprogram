/* fahrenheit to centrigrade conversion*/
#include<stdio.h>
int main()
{
	float  c,f;
	printf("\n enter the temparature in fahrenheit=");
	scanf("%f",&f);
	c=(f-32)*0.5;
	printf("\n temparature in centrigrade is %f",c);
	return 0;
}
