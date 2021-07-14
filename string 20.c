/*enter a string.enter a search word and print frequency of that word*/
#include <stdio.h>
#include <string.h>
void main()
{
    int i, j, l, l1, l2;
    char str[100],s[100];
	int ct=0,ct1=0;
 	printf("\nEnter a string : ");
    scanf("%[^\n]s",str);
 	l1=strlen(str);
 	printf("\nEnter a substring : ");
    scanf(" %[^\n]s",s);
 	l2=strlen(s);
 	for(i=0;i<l1;i++)
    {
        j=0;
        ct=0;
        while(str[i]==s[j] || str[i]==s[j]-32 || str[i]-32==s[j])
        {
            ct++;
            i++;
            j++;
        }
        if(ct==l2&&(str[i]=='.'||str[i]==' '))
        {
//            printf("%c",str[i]);
			ct1++;                                   
            ct=0;
        }
//        else
//            i++;
    }    
    printf(" %s occurs %d times in %s",s,ct1,str);
}
