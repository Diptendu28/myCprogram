/*Input a string.print the longgest word.*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int mark=0,size=0,count,i=0;
	printf("\nEnter the sentence following a full stop:");
	gets(str);
	while(str[i]!='\0')
	{
		count=0;
		while(str[i]!=' ')
		{
			if(str[i]=='.')
				break;
			i++;
			count++;
		}
		if(count>size)
		{
			size=count;
			mark=i-size;
		}
		i++;
	}
//	printf("%d,%d,%d,%d",i,count,mark,size);
	printf("\nThe longest word is:");
	while(size)
	{
		printf("%c",str[mark]);
		mark++;
		size--;
	}
	return 0;
}
