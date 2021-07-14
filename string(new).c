/*enter multiple string. print all words.Also print all special characters,print the occurance of those special characters*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	char c;
	printf("enter the no of characters: ");
	scanf("%d",&n);
    char *str=(char*)malloc(sizeof(char)*n);
//  fflush(stdin);
	int i,sp[33];
	printf("Enter the string: ");
//	gets(str);
	scanf(" %[^\n]s",str);
	
	//printing word by word
	for (i=0; str[i]!='\0'; i++)
	{
		c=str[i];
		if (str[i]==' ')
			printf("\n");
		else if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
			printf("%c", str[i]);
		else
			continue;
	}
	for (i=0;i<33;i++)
		sp[i]=0;
	for (i=0; str[i]!='\0'; i++) //calculating frequency of each special character
	{
		if (str[i]>=32 && str[i]<=47)
			sp[str[i]-32]++;
		if (str[i]>=58 && str[i]<=64)
			sp[str[i]-58+16]++;
		if (str[i]>=91 && str[i]<=96)
			sp[str[i]-91+23]++;
		if (str[i]>=123 && str[i]<=126)
			sp[str[i]-123+29]++;
	}
	printf("\n");
	for (i=0; i<16; i++)
	{
	 	c=i+32;
         if (sp[i]!=0)
         {
         	printf("\n");
			 printf("%c -> %d",c, sp[i]);
		 }
	}
	for (i=16; i<23; i++)
	{
		c=i+42;
        if (sp[i]!=0)
		{
        	printf("\n");
        	printf("%c -> %d",c, sp[i]);
		}
	}
	for (i=23; i<29; i++)
	{
	 	c=i+68;
        if(sp[i]!=0)
		{
			printf("\n");
		 	printf("%c -> %d",c, sp[i]);
		}
	}
	for (i=29; i<33; i++)
	{
	 	c=i+94;
         if (sp[i]!=0)
		 {
         	printf("\n");
         	printf("%c -> %d",c, sp[i]);
		 }
	}
	return 0;
}
