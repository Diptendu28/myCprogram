/*Create a text file to store few sentences. 
Write functions to display no. of words, no. of sentences and no. of vowels in it*/
#include<stdio.h>
#include<stdlib.h>
void readFile(FILE *fptr, char *fname) 
{
	
	fptr = fopen(fname,"r");
//   printf("Now the file contents:\n");
   if(fptr==NULL)
   {
      printf("Error in opening file!");
      exit(3);
   }
	char ch;
	int s=0,v=0,w=0;
	ch=fgetc(fptr);
	while(ch!=EOF)
	{ 
		printf("%c",ch);
		if(ch==' ')
			w++;
		if(ch=='.'||ch=='?'||ch=='!')
			s++;
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
			v++;
		ch=fgetc(fptr);
	}
	fclose(fptr);
	printf("no of sentence is %d\n",s);
	printf("no of words is %d\n",w+1);
	printf("no of vowel is %d",v);
    
}
int main()
{
   char str[1000];
   FILE *fptr;
   char fname[20];
   printf("\nEnter the file name to create: ");
   scanf("%s",fname);
   fptr=fopen(fname,"w");	
   if(fptr==NULL)
   {
      printf("Error in opening file!");
      exit(1);
   }
   printf("Input a sentence for the file: ");
   fflush(stdin);
   fgets(str, sizeof str, stdin);
   fprintf(fptr,"%s",str);
   printf("\n The file %s is created successfully.\n",fname);
   fclose(fptr);
   readFile(fptr,fname);
   return 0;
}
