/*input two date.Print the number of days between them*/
#include<stdio.h>
struct Date 
{ 
	int d,m,y; 
}; 
const int monthDays[12]={31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
int countLeapYears(Date d) 
{ 
    int years=d.y;
    if (d.m<=2) 
        years--;  
    return years/4-years/100+years/400; 
} 
int diff(Date dt1, Date dt2) 
{ 
    long int ct1,ct2;
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 
    ct1=dt1.y*365 + dt1.d; 
  	// Add days for months in given date 
    for(int i=0;i<dt1.m-1;i++) 
        ct1+=monthDays[i]; 
    ct1+=countLeapYears(dt1); // every leap year is of 366 days,Add a day for every leap year 
  	ct2 = dt2.y*365 + dt2.d; 
    for(int i=0;i<dt2.m-1;i++) 
        ct2+=monthDays[i]; 
    ct2+=countLeapYears(dt2);  
    return(ct2 - ct1); 
} 
int main() 
{ 
	struct Date dt1,dt2;
	printf("enter the day of 1st date");
    scanf("%d",&dt1.d);
    printf("enter the month of 1st date");
    scanf("%d",&dt1.m);
    printf("enter the year of 1st date");
    scanf("%d",&dt1.y);
    printf("enter the day of 2nd date");
    scanf("%d",&dt2.d);
    printf("enter the month of 2nd date");
    scanf("%d",&dt2.m);
    printf("enter the year of 2nd date");
    scanf("%d",&dt2.y);
    printf("Difference between two dates is %d",diff(dt1, dt2)); 
  	return 0; 
} 
