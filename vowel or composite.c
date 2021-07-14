/* vowel or composite*/
#include <stdio.h>
int main(){
char a;
printf("enter the alphabet");
scanf("%c",&a);
switch(a){
case 'A':
case 'E':
case 'I':
case 'O':
case 'U':
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':printf("vowel");
break;
default: printf("composite");
}
return 0;
}
