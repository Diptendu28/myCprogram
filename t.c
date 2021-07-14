/*create and input data in a file and also add new record and display this*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
   char str[1000];
   char dataToAppend[100];
   FILE *fptr;
   char fname[20]="Diptendu.txt";
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
   fptr=fopen(fname,"a");
   if (fptr==NULL)
   { 
   		printf("\nUnable to open '%s' file.\n", fname);
   		printf("Please check whether file exists or not!\n");
   		exit(2); 
   }
   printf("Enter data to append: ");
   fflush(fptr);
   fgets(dataToAppend, sizeof dataToAppend, stdin);
   fputs(dataToAppend, fptr);
   printf("\nSuccessfully appended to the file.\n");
   fclose(fptr);
   fptr = fopen(fname,"r");
   printf("Now the file contents:\n");
   if(fptr==NULL)
   {
      printf("Error in opening file!");
      exit(3);
   }
	char ch;
	ch=fgetc(fptr);
	while(ch!=EOF)
	{ 
		printf("%c",ch);
		ch=fgetc(fptr);
	}
   fclose(fptr);
//   fptr=fopen(fname,"w");
//   fclose(fptr);	
   return 0;
}
