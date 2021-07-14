/*abcde
  abcd
  abc
  ab
  a  */

#include<stdio.h>
int main()
{
	char ch,ch2;
	for(ch='e';ch>='a';ch--)
	{
		for(ch2='a';ch2<=ch;ch2++)
		{
			printf("%c",ch2);
		}
		printf("\n");
	}
}
