/*input a time in hour,min,sec format and also add another time and print the new time*/
#include <stdio.h>
struct TIME 
{
   int seconds;
   int minutes;
   int hours;
}startTime, stopTime,add;
int day=0;
void addedTimePeriod(TIME startTime,TIME stopTime);
int main() 
{
   printf("enter the time in 24 format");
   printf("Enter the start time. \n");
   printf("Enter hours: ");
   scanf("%d", &startTime.hours);
   printf("Enter minutes: ");
   scanf("%d", &startTime.minutes);
   printf("Enter seconds: ");
   scanf("%d", &startTime.seconds);
   printf("Enter the stop time. \n");
   printf("Enter hours: ");
   scanf("%d", &stopTime.hours);
   printf("Enter minutes: ");
   scanf("%d", &stopTime.minutes);
   printf("Enter seconds: ");
   scanf("%d", &stopTime.seconds);
   addedTimePeriod(startTime, stopTime);
   printf("\n added time: %d:%d:%d + ", startTime.hours,startTime.minutes,startTime.seconds);
   printf("%d:%d:%d ", stopTime.hours,stopTime.minutes,stopTime.seconds);
   printf("= %d day : %d  hours : %d minutes :%d seconds\n",day, add.hours,add.minutes,add.seconds);
   return 0;
}
void addedTimePeriod(TIME startTime ,TIME stopTime) 
{
   add.seconds=startTime.seconds+stopTime.seconds;
   while(add.seconds>=60)
   {
   		add.minutes=add.minutes+add.seconds/60;
		add.seconds=add.seconds%60;
   }
   add.minutes+=startTime.minutes+stopTime.minutes;
   while(add.minutes>=60)
   {
		add.hours+=add.minutes/60;
		add.minutes=add.minutes%60;
   }
   add.hours+=startTime.hours+stopTime.hours;
   if(add.hours>=24)
   {
   		day=add.hours/24;
   		add.hours=add.hours%24;
   }
}
