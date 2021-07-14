/*input todays date and also input dob of someone..and print the age of that person*/
#include<stdio.h>
struct Date 
{
	int d,m,y;
};
void main()
{
	struct Date today,DOB,age;
	printf("enter today's day,month,year");
	scanf("%d",&today.d);
	scanf("%d",&today.m);
	scanf("%d",&today.y);
	printf("enter DOB");
	scanf("%d",&DOB.d);
	scanf("%d",&DOB.m);
	scanf("%d",&DOB.y);
	if(today.d<DOB.d)
	{
		today.d+=30;
		today.m--;
	}
	age.d=today.d-DOB.d;
	if(today.m<DOB.m)
	{
		today.y--;
		today.m+=12;
	}
	age.m=today.m-DOB.m;
	age.y=today.y-DOB.y;
	printf("age: %d years- %d month - %d days",age.y,age.m,age.d);
}
