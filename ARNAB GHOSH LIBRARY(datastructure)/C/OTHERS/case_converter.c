#include<stdio.h>
#include<string.h>
int main(void)
{
	char i[100];
	char o[100];
	int d,x;
	printf("Enter anything to convert:\n");
	// Use any one of these function to print space in a string //
	gets(i);
	//scanf("%[^\n]%*c",i);
	//fgets(i,100,stdin);
	d=strlen(i);

	for(x=0;x<d;x++)
	{
		if(i[x]>64&&i[x]<91)
			o[x]=i[x]+32;
		else if(i[x]>96&&i[x]<123)
			o[x]=i[x]-32;
		else
			o[x]=i[x];
	}
	printf("the output\n");
	puts(o);
	return 0;
}
