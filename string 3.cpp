/*input a string and print the frequency of the vowels*/
#include<stdio.h>
#include<string.h>
int main()
{
	int l,i,j=0,ct1=0,ct2=0,ct3=0,ct4=0,ct5=0;
	char st[10],rev[10];
	printf("\nEnter the string:");
	gets(st);
	l=strlen(st);
	for(i=0;i<l;i++)
	{
		if(st[i]=='A'||st[i]=='a') 
		ct1++;
		if(st[i]=='E'||st[i]=='e')
		ct2++;
		if(st[i]=='I'||st[i]=='i')
		ct3++;
		if(st[i]=='O'||st[i]=='o')
		ct4++;
		if(st[i]=='U'||st[i]=='u')
		ct5++;
	} 
	printf("\nThe frequency of 'A' is %d",ct1);
	printf("\nThe frequency of 'E' is %d",ct2);
	printf("\nThe frequency of 'I' is %d",ct3);
	printf("\nThe frequency of 'O' is %d",ct4);
	printf("\nThe frequency of 'U' is %d",ct5);
}
