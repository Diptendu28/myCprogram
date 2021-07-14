#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
int main(void){
    char str[max];
    printf("Enter the Word: ");
    gets(str);
    for(int i = 0; i < strlen(str); i++)
        printf("\n%c\n", str[i]);
    system("pause");
    return 0;
}
