/*Input a word.Print the word by alphabetical order*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int hash[256]={0},i=0,j;
	printf("\nEnter the word:");
	gets(str);
	while(str[i])
	{
		if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			hash[str[i]+32]++;
		else			
			hash[str[i]]++;
		i++;
	}
	printf("The word in alphabetic order:");
	for(i=0;i<256;i++)
		if(hash[i])
			for(j=0;j<hash[i];j++)
				printf("%c",i);
	return 0;
}
