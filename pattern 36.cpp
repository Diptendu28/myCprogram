/*  a
   aba
  abcba
 abcdcba
abcdedcba */
#include<stdio.h>
int main()
{
	char ch,ch2,ch3,ch4;
	int i,j;
	for(ch='a';ch<='e';ch++)
	{
		for(j=1;j<=5-i;j++)
		{
			printf(" ");
		}
		for(ch3='a';ch3<=ch;ch3++)
		{
			printf("%c",ch3);
		}
		for(ch4=ch-1;ch4>='a';ch4--)
		{
			printf("%c",ch4);
		}
		printf("\n");
		i++;
	}
}
