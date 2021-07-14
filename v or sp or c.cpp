/*vowel or special character or consonant*/
#include<stdio.h>
int main()
{
	char v='a';
	printf("\n enter a character");
	scanf("%c",&v);
	switch(v)
	{
		case'a':case'e':case'i':case'o':case'u':case'A':case'E':case'I':case'O':case'U':
			printf("\n vowel");
			break;
		case',':case'.':case'?':case'!':
		printf("\n special charater");
			break;
		default:
		printf("\n consonant");
		
	}
}
