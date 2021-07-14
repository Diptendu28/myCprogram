/* abcdedcba
   abcd dcba
   abc   cba
   ab     ba
   a       a */
#include<stdio.h>
int main()
{
	char ch,ch2,ch3;
	int k,i=1;
	for(ch='e';ch>='a';ch--)
	{ 
		for(ch2='a';ch2<=ch;ch2++)
		{
			printf("%c",ch2);
		}
		for(k=1;k<=2*i-3;k++)
		{
			printf(" ");
		}
		for(ch3=ch;ch3>='a';ch3--)
		{
			if(ch3<'e')
			printf("%c",ch3);
		}
		printf("\n");
		i++;
	}
	
}
