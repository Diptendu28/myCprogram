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
	{
		rev[j++]=st[i];
	}
	rev[j]='\0';
	printf("\nReverse wors is %s",rev);
}
