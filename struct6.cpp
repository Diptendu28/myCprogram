/*Find the day of a given date */
#include <stdio.h>
struct date
{
	int d, m, y;
}d1;
int main() 
{	int weekday;	
	printf("Enter date, month and year: ");	
	scanf("%d%d%d",&d1.d,&d1.m,&d1.y);
	weekday=(d1.d+=d1.m<3?d1.y--:d1.y-2,23*d1.m/9+d1.d+4+d1.y/4-d1.y/100+d1.y/400)%7 ;	
	printf("The day of the week is : ");
	switch(weekday) 
	{
		case 0:
			printf("Sunday.\n");
			break;
		case 1:
            printf("Monday.\n");
			break;
		case 2:
            printf("Tuesday.\n");
			break;
		case 3:
            printf("Wednesday.\n");
			break;
		case 4:
            printf("Thursday.\n");
			break;
		case 5:
            printf("Friday.\n");
			break;
		case 6:
            printf("Saturday.\n");
	}
	return 0;
}
