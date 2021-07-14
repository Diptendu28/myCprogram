/* taxi bill*/
#include<stdio.h>
int main()
{
	float distance=0.0,rate=0.0,amt=0.0;
	printf("\n enter the distance");
	scanf("%f",&distance);
	if(distance<=10)
	{
		amt=40;
	}
	if(distance>10&&distance<=20)
	{
		amt=40+5*(distance-10);
	}
	if(distance>20)
	{
		amt=40+6*(distance-10);
	}
	printf("\n taxi bill is %f",amt);
}




