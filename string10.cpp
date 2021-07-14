/*Input a string.search for a word whether that word present in that string or not.If it is there.print that word...*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],word[10],w[10];
	int i=0,j,l,found=0;
	printf("\nEnter the string:");
	gets(str);
	strcat(str," ");
	l=strlen(str);
	printf("\nEnter the word you want to search:");
	gets(word);
	j=0;
	for(i=0;i<l;i++)
	{
		if(str[i]!=' ')
			w[j++]=str[i];
		else
			{
				w[j]='\0';
				
				if(strcmp(w,word)==0)
				{
					printf("\nThe word '%s' present in the string",word);
					found=1;
				}
				j=0;
			}
	}
	if(found==0)
		printf("\nThe word '%s' is not found",word);
}
