/*Swap the small letter into capital and capital into small*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int i;
	printf("\nEnter the word:");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
		    str[i]=str[i]+32;
		}
		else if(str[i]>='a'&&str[i]<='z')
		{
		    str[i]=str[i]-32;
		}
	}
	printf("%s",str);
	return 0;
}

