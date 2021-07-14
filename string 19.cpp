/*string(13)....modified */
#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	int hash[256]={0},i=0,j;
	printf("\nEnter the word:");
	gets(str);
	while(str[i])
	{
//		if(str[i]>='A'&& str[i]<='Z')
//			hash[str[i]+32]++;
//		else			
			hash[str[i]]++;
		i++;
	}
	printf("The word in alphabetic order:");
	for(i=97;i<=122;i++)
	{
		if(hash[i]!=0)
		{
			for(j=0;j<hash[i];j++)
				printf("%c",i);
		}
		if(hash[i-32])
		{
			for(j=0;j<hash[i-32];j++)
				printf("%c",i-32);
		}
	}
	return 0;
}
