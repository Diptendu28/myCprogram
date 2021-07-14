/*Input a string.print the duplicate words...*/
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],w[10],m[10];
	int i=0,j,l,k=0,p=0;
	printf("\nEnter the string:");
	gets(str);
	strcat(str," ");
	l=strlen(str);
	j=0;
	for(i=0;i<l;i++)
	{
		if(str[i]!=' ')
			w[j++]=str[i];
		else
			{
				w[j]='\0';
				for(k=i+1;k<l;k++)
				{
					if(str[k]!=' ')
						m[p++]=str[k];
					else
					{
						m[p]='\0';
						if(strcmp(m,w)==0)
							printf("\n'%s' is the duplicate word",w);
						p=0;
					}
				}
				j=0;
			}
	}
}
