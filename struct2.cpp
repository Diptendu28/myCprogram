/*input a date and also input no of days.calculate the date after the given number of days and print it*/
#include<stdio.h>
struct Date
{
	int d,m,y;
}dt,a;
const int monthDays[13]={0,31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31};
int main()
{
	int n;
	printf("enter day,month,year");
	scanf("%d",&dt.d);
	scanf("%d",&dt.m);
	scanf("%d",&dt.y);
	printf("enter a day");
	scanf("%d",&n);
	a.d=dt.d;
	a.m=dt.m;
	a.y=dt.y;
	int rd=monthDays[a.m]-a.d;
	if(rd>n)
		a.d=a.d+n;
	else
	{
		n=n-rd;
		a.m++;
		while(monthDays[a.m]<n)
		{
			n=n-monthDays[a.m];
			a.m++;
			if(a.m>12)
			{
				a.m=1;
				a.y++;
			}
		}
		a.d=n;
	}
	printf("date:%d/%d/%d",a.d,a.m,a.y);
	return 0;
}
