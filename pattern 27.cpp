/* a
   aba
   abcba
   abcdcba
   abcdedcba */
#include<stdio.h>
int main()
{
	char ch,ch2,ch3;
	for(ch='a';ch<='e';ch++)
	{
		for(ch2='a';ch2<=ch;ch2++)
		{
			printf("%c",ch2);
		}
		for(ch3=ch-1;ch3>='a';ch3--)
		{
			printf("%c",ch3);
		}
		printf("\n");
	}
}
