#include<stdio.h>
#include<math.h>


/*void toh(int n, char s , char d, char t)
{
	if(n>=1)
	{
		toh(n-1,s,t,d);
		printf("\n%c -> %c",s,d);
		toh(n-1,t,d,s);
	}
}

*/


void toh(int n, char s ,char t, char d){
	if(n==1){
		printf("\n%c -> %c",s,d);
        return ;
		
	}
    else{
        toh(n-1,s,d,t);
        toh(1, s, t, d);
        toh(n-1,t,s,d);
    }
}


int main()
{
	int n;
	char s='A',d='B',t='C';
	printf("\nEnter number of disk:");
	scanf("%d",&n);
	toh(n,s,d,t);
	printf("\nThe number of moves = %d",(int)pow(2,n)-1);
	return 0;
}



/*
Enter number of disk:4

A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
A -> B
C -> B
C -> A
B -> A
C -> B
A -> C
A -> B
C -> B
The number of moves = 15

*/











/*#include<stdio.h>
#include<math.h>
void toh(int n, char s , char d, char t){
	if(n>=1){
		toh(n-1,s,t,d);
		printf("\n%c -> %c",s,d);
		toh(n-1,t,d,s);
	}
}

int main(){
	int n;
	char s='S',d='D',t='T';
	printf("\nEnter number of disk:");
	scanf("%d",&n);
    printf("The number of moves = %d",(int)pow(2,n)-1);
	toh(n,s,t,d);
	return 0;
}

*/

/*
  void toh(int n, char s ,char t, char d){
	if(n==1){
		printf("\n%c -> %c",s,d);
        return ;
	}
    else{
        toh(n-1,s,d,t);
        toh(1, s, t, d);
        toh(n-1,t,s,d);
    }
}

*/









/***
void toh(int n, char s , char d, char t){
	if(n>=1){
		toh(n-1,s,t,d);
		printf("\n%c -> %c",s,d);
		toh(n-1,t,d,s);
	}
}
*/