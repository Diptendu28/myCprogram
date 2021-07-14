/* checking of angle of a traingle*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	printf(" enter 1st angle");
	scanf("%d",&a);
	printf("enter 2nd angle");
	scanf("%d",&b);
	printf("enter 3rd angle");
	scanf("%d",&c); 
	if(a==90||b==90||c==90)
	{
		printf(" the angle is right angle\n");
	}
	if(a<90&&b<90&&c<90)
	{
		printf(" the angle is  acute angle\n");
	}
	if(a>90||b>90||c>90)
	{
		printf("the angle is obtuse angle\n");
	}
}
	

	

