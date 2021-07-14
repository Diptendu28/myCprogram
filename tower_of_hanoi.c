#include<stdio.h>
void TOH(int n,char source,char inter,char desti)
{
	if(n==1)
	{
		printf("\nfrom %c to %c",source,desti);
		return;
	}
	else
	{
		TOH(n-1,source,desti,inter);
		TOH(1,source,inter,desti);
		TOH(n-1,inter,source,desti);
	}
}
int main()
{
	int n;
 	printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    TOH(n,'A','B','C');
    return 0;
}
