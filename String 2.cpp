/*Input a Wors.check it is palindrome or not*/
#include<stdio.h>
#include<string.h>
int main()
{
	int l,i,j=0;
	char st[10],rev[10];
	printf("\nEnter the words:");
	gets(st);
	l=strlen(st);
	for(i=l-1;i>=0;i--)
		rev[j++]=st[i];
	if(strcmp(st,rev)==0)
		printf("\nThe word is palindrome");
	else
		printf("\nThe word is not palindrome");
}
