/*input a string.search for a word.whether it is there or not.*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],word[10];
	int i=0,j,flag=0;
	printf("\nEnter the string:");
	gets(str);
	printf("\nEnter the keyword you want to search");
	gets(word);
	while(str[i])
	{
		j=0;
		if(str[i]==word[j])
		{
			flag=1;
			while(word[j])
			{
				if(str[i]!=word[j])
				{
					flag=0;
					break;	
				}
				i++;
				j++;		
			}	
		}
		if(flag)
			break;
		i++;
	}
	if(flag)
		printf("The word '%s' is present in the string",word);
	else
		printf("The word'%s'is not present in the string",word);
}

