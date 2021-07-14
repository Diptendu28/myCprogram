/*Input a string..Print the string by ascending ord2er.*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,mark[30],size[30],count=0,n=0,c;
	char str[100];
	printf("\nEnter the sentence followed by a full stop:");
	gets(str);
	while(str[i])
	{
		count++;
		if(str[i]==' '||str[i]=='.')
		{
			size[j]=count-1;
			mark[j]=i-(count-1);
			j++;
			n++;
			count=0;
		}
		i++;
	}
	printf("\nThe arranged sentence in order of the length of words is as follows:");
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
			if(size[j]>size[count])
				count=j;
			c=0;
		for(j=mark[count];c<size[count];j++)
		{
			printf("%c",str[j]);
			c++;
		}
		if(i==n-1)
			printf(".");
		else
			printf(" ");
		size[count]=0;
	}
	return 0;
}
