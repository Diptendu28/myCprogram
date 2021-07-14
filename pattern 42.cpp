/* A B C D E F G F E D C B A
   A B C D E F   F E D C B A
   A B C D E       E D C B A
   A B C D           D C B A
   A B C               C B A
   A B                   B A
   A                       A */

#include<stdio.h>
int main()
{
	char ch,ch2,ch3;
	int k,i=1;
	for(ch='G';ch>='A';ch--)
	{ 
		for(ch2='A';ch2<=ch;ch2++)
		{
			if(ch2<'G')
			{
				printf("%c ",ch2);	
			}
			else
			{
				printf("%c",ch2);
			}
		}
		for(k=1;k<=4*i-7;k++)
		{
			printf(" ");
		}
		for(ch3=ch;ch3>='A';ch3--)
		{
			if(ch3<'G')
			printf(" %c",ch3);
		}
		printf("\n");
		i++;
	}
}
