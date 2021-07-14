/*create a struct time T with member variable h.m.s. Input two times and calculate the duration between them.*/
#include <stdio.h>
struct TIME
{
	int seconds;
	int minutes;
	int hours;
};
int main()
{
	struct TIME startTime, stopTime, diff;
	printf("Enter start time: \n");
	printf("Enter hours, minutes and seconds respectively: ");
	scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
	printf("Enter stop time: \n");
	printf("Enter hours, minutes and seconds respectively: ");
	scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);
	diff.seconds = startTime.seconds - stopTime.seconds;
	diff.minutes = startTime.minutes - stopTime.minutes;
	diff.hours = startTime.hours - stopTime.hours;
	if(diff.seconds>60)
	{
		diff.minutes=diff.minutes+diff.seconds/60;
		diff.seconds=diff.seconds%60;
	}
	if(diff.minutes > 60)
	{
		diff.hours+=diff.minutes/60;
		diff.minutes=diff.minutes%60;
	}
	printf("\nTIME DIFFERENCE: %d:%d:%d - ", startTime.hours, startTime.minutes, startTime.seconds);
	printf("%d:%d:%d ", stopTime.hours, stopTime.minutes, stopTime.seconds);
	printf("= %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);
	return 0;
}

