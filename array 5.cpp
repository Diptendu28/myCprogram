/* enter roll no and print corresponding marks */
#include<stdio.h>
int main()
{
	int i,r[20],n[20],srh;
	for(i=0;i<20;i++)
	{
		printf("enter roll no");
		scanf("%d",&r[i]);
		printf("enter corresponding number");
		scanf("%d",&n[i]);
	}
	printf("enter the search roll no");
	scanf("%d",&srh);
	for(i=0;i<20;i++)
	{
		if(r[i]==srh)
		{
			printf("the marks of %d is %d",r[i],n[i]);
			break;
		}
	}
}
