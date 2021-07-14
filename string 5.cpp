/*input a string .freuency of words in that string*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,count=0;
	char arr[50];
	printf("enter the string");
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	{
		char ch=arr[i];
		if(ch==' ')
		count++;
	}
	printf("number of words are %d",count+1);
}
