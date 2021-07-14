/*nam modicfiaction*/
#include<stdio.h>
int main()
{
	char s1[100],s2[100],t;
	int i,count1=0,count2=0,x,y;
	printf("Enter the 1st string:");
	gets(s1);
	printf("\nEnter the 2nd string:");
	gets(s2);
	for(i=0;i<s1[i]!='\0';i++)
		count1++;
	for(i=0;i<s2[i]!='\0';i++)
		count2++;
	x=count1/2-1;
	y=count2-1;
	t=s1[x];
	s1[x]=s2[y];
	s2[y]=t;
	printf("\n The 1st alteres strings is:%s\naltered 2nd string is:%s",s1,s2);
	return 0;
}
