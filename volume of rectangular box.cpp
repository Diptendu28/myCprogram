/* volume of a rectangular box*/
#include<stdio.h>
#include<math.h>
int main()
{
	int v=0,w=0,h=0,l=0;
	printf("\n enter the length=");
	scanf("%d",&l);
	printf("\n enter the width=");
	scanf("%d",&w);
	printf("\n enter the height=");
	scanf("%d",&h);
	v=l*w*h;
	printf("\n the volume is %d" ,v);
	return 0;
}
