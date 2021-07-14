/* a
   bb
   ccc
   dddd
   eeeee */
#include<stdio.h>
int main()
{
	char ch,ch2;
	for(ch='a';ch<='e';ch++)
	{
		for(ch2='a';ch2<=ch;ch2++)
		{
			printf("%c",ch);
		}
		printf("\n");
	}
}
