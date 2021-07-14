#include<stdio.h> 
int main(void){
    int i = 1;
    while (printf("%d",5) == 1 == i){
        printf("Loop");
    }
    return 0;
} 


/*

#include<stdio.h>
#include<stdlib.h>
#include"printIO.h"
int main(){
	OpenIO(fopen("test.c","a"));
    char arr[3];
    scanf("%s", arr);
    printf("%s", arr);

    return 0;
}

in: 77354545875545
out: 77354545875545

*/