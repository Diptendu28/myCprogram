/*a
  ba
  cba
  dcba
  edcba */
#include<stdio.h>
int main()
{
	char ch,ch2;
	for(ch='a';ch<='e';ch++)
	{
		for(ch2=ch;ch2>='a';ch2--)
		{
			printf("%c",ch2);
		}
		printf("\n");
	}
}
