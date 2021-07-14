/* let us c -page303 (f)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void abk();
void dbk();
void aabk();
void tbk();
void nbk();
void lbk();
void ebk();

struct library
{
 	int accession,cost,n;
 	char tittle[20],author[20],name[20],flag[5];
}b[10];
int i=0;

int main()
{
 	char choice;
 	while(1)
 	{
		fflush(stdin);
		printf("\nif you want to Add book information , Then enter A or a ");
 		printf("\nif you want to display book information ,then enter B or b");
 		printf("\nif you want to know Author books,then enter C or c");
 		printf("\nif you want to list the tittle of the specified book,then enter D or d");
 		printf("\nif you want to know number of the books,then enter E or e");
 		printf("\nif you want to List books in the order of accession number ,then enter F or f");
 		printf("\nIf you want to exit,then enter G or g"); 
// 		printf("\nIf you want to clear the screen,Then enter H or h");
		printf("\nEnter your choice:");
 		scanf("%c",&choice);
 		switch(choice)
 		{
  			case 'a':  abk(); 
			  break;
  			case 'b': dbk(); 
			  break; 
  			case 'c': aabk();
			  break;
  			case 'd': tbk(); 
			  break;
  			case 'e': nbk(); 
			  break;
  			case 'f': lbk(); 
			  break;
  			case 'A':  abk(); 
			  break;
  			case 'B': dbk(); 
			  break; 
  			case 'C': aabk();
			  break;
  			case 'D': tbk(); 
			  break;
  			case 'E': nbk(); 
			  break;
  			case 'F': lbk(); 
			  break;
    		case 'g' :exit(5); 
			  break;
      		case 'G' :exit(5); 
			  break;
//   case 'h' :system("cls"); break;   // clear output screen
//   case 'H' :system("cls"); break; 
   			default :
			   printf("\nThere is no selection for %c",choice);
   		}
	}
}

//ADDING INFORMATON
void abk()
{
 	printf("\nEnter accession number:");
 	scanf("%d",&b[i].accession);
 	printf("Enter Book name:");
 	scanf("%s",b[i].tittle);
 	printf("Enter author name:");
 	scanf("%s",b[i].author);
 	printf("Enter book price:");
 	scanf("%d",&b[i].cost);
	printf("BOOK ISSUMENT\t(yes or no):");
 	scanf("%s",b[i].flag);
// 	fflush(stdin);
	i++;
}

//DISPLAYING INFORMATION
void dbk()
{
 	int j;
 	char str[3]={'y','e','s'};
 	for(j=0;j<i;j++)
	{
 		printf("\naccession number is %d\n",b[j].accession);
 		puts(b[j].tittle);
 		puts(b[j].author);
 		printf("book price is :%d",b[j].cost);
		if(strcmp(b[j].flag,str)==0)
  		{
   			printf("issued\n");
  		}
  		else
   			printf("\n not issued");
  	}
}

//AUTHOR BOOK INFORMATION
void aabk()
{
	int j;  
	char a2[20];
	printf("\nEnter author name :");
	scanf("%s",a2);
 	for(j=0;j<i;j++)
	{
 		if(strcmp(b[j].author,a2)==0)
 		{
// 			printf("\naccession number is %d\n",b[j].accession);
			puts(b[j].tittle);
//			puts(b[j].author);
// 			printf("book price is :%d",b[j].cost);
 			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
 		}
 		else if(strcmp(b[j].author,a2)!=0)
  			printf("\nThere is no belongs to  %s books",a2);
	}
	if(i==0)  
		printf("\nThere is no belongs to  %s books",a2);
}

//SPECIFIED BOOK
void tbk()
{
	char book[20];
	int j;
 	printf("\nEnter a book name");
 	gets(book);
  	for(j=0;j<i;j++)
	{
 		if(strcmp(b[j].tittle,book)==0)
 		{
 			printf("\naccession number is %d\n",b[j].accession);
			puts(b[j].tittle);
			puts(b[j].author);
 			printf("book price is :%d",b[j].cost);
		}
 		else if(strcmp(b[j].tittle,book)!=0)
 			printf("\nThere is no %s  book",book);
	    printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	if(i==0) 
		printf("There is no %s book",book);
}
//NUMBER OF BOOKS IS THERE

void nbk()
{
 	int j,k=0;
 	for(j=0;j<i;j++)	
  		k++;
  	if(k>1)
 		printf("\n%d books",k);
 	else if(k==1)
 		printf("\n%d book",k);
 	else
 		printf("\nThere are no books");
  	printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}
//ASCENDING ORDER OF ACCESSION NUMBER
void lbk()
{
 	int j,k,temp;
 	for(j=0;j<i;j++)
 	{
  		for(k=0;k<i-1;k++)
 		{
  			if(b[k].accession>b[k+1].accession)
  			{
   				temp=b[k].accession;
   				b[k].accession=b[k+1].accession;
   				b[k+1].accession=temp;
  			}
 		}
   	}
	for(j=0;j<i;j++)
	{
 		printf("\naccession number is %d\n",b[j].accession);
		puts(b[j].tittle);
		puts(b[j].author);
 		printf("book price is :%d",b[j].cost);
   		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}	
} 
