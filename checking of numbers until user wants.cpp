/* count number of positives,negative, zero until user want by using loop*/
#include<stdio.h>
int main()  
{
	int num;
	char choice;
	do
	{
		printf(" enter a number\n");
		scanf("%d",&num);
		if(num==0)
		printf("number is zero\n");
		else if(num>0)
		printf("number is positive\n");
		else
		printf("number is negative\n");
		printf("\n\nwant to continue again(press y/Y for 'yes'):");
		scanf(" %c",&choice);
	}while(choice=='Y' || choice=='y');
	printf(" bye bye!!\n");
	return 0;
}
