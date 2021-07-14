#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int hash[256]={0},i,j;
	printf("\nEnter the word:");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
			continue;
		else if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			hash[str[i]+32]++;
		else			
			hash[str[i]]++;
	}
	printf("The word in alphabetic order:");
	for(i=0;i<256;i++)
		if(hash[i])
			for(j=0;j<hash[i];j++)
				printf("%c",i);
	return 0;
}

