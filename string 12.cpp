/*Input a word.encrypte the word.print that encrtpted word.*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int i=0,c;
	printf("\nEnter the word:");
	gets(str);
	while(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='A'&&str[i]!='E'&&str[i]!='I'&&str[i]!='O'&&str[i]!='U')
		i++;
	c=i;
	printf("The encrypted code is:");
	while(str[i])
		printf("%c",str[i++]);
	i=0;
	while(i<c)
		printf("%c",str[i++]);
	printf("ay");
	return 0;
}
