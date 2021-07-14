/* harshad number*/
#include<stdio.h>
int main()
{
	int num,rem,temp,sum=0;
	printf("enter a number");
	scanf("%d",&num);
	temp=num;

		while(temp!=0)
		{
			rem=temp%10;
			sum=sum+rem;
			temp=temp/10;
		}
	if(num%sum==0)
	printf("%d =harshad number",num);
	else
	printf("%d=not a harshad number",num);
}
