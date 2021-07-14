/*let us c page -303 (d)*/
#include<stdio.h>
void main()
{
	struct cricket
	{
		char pname[30];
		int age;
		int test_m;
		float avg;
	};
	int i,j,n;
	printf("enter value of n:");
	scanf("%d",&n);
	struct cricket player[n];
	struct cricket temp;
	float dummy;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\n Player name: ");
		gets(player[i].pname);
		//fflush(stdin);
		printf("\n Age: ");
		scanf("%d",&player[i].age);
		printf("\n test matches : ");
		scanf("%d",&player[i].test_m);
//		fflush(stdin);
		printf("\n Average runs: ");
		scanf("%f",&dummy);
		fflush(stdin);
		player[i].avg=dummy;
	}
	printf("\nbefore rearranging");
	for(i=0;i<n;i++)
	{
		printf("\n Name: %s",player[i].pname);
		printf("\n Age: %d",player[i].age);
		printf("\n Age: %d",player[i].test_m);
		printf("\n Average: %.2f",player[i].avg);
		printf("\n*************");
		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(player[j+1].avg>player[j].avg)
			{
				temp=player[j];
				player[j]=player[j+1];
				player[j+1]=temp;
			}
		}
	}
	printf("after rearranging");
	for(i=0;i<n;i++)
	{
		printf("\n Name: %s",player[i].pname);
		printf("\n Age: %d",player[i].age);
		printf("\n Age: %d",player[i].test_m);
		printf("\n Average: %.2f",player[i].avg);
		printf("*************");
		
	}
}
