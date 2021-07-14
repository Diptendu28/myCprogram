/*INPUT A SENTENCE . PRINT THE NUMBER OF VOWELS*/
#include<stdio.h>
#include<string.h>
int main()
{
	int l,v=0,i;
	char ch,st[200];
	printf("\nEnter a text");
	gets(st);
	l=strlen(st);
	for(i=0;i<l;i++)
	{
		ch=st[i];
		switch(ch)
		{
			case'a':case'e':case'i':case'o':case'u':case'A':case'E':case'I':case'O':case'U':
			v++;
			break;
		}
	}
	printf("no of vowels = %d",v);
}
