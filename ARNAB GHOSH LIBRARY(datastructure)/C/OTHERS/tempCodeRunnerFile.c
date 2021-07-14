#include<stdio.h>
int main(void){
    int c3 = 0, c5 = 0;
    for(int i = 1; i <= 20; i++){
        c3++;
        c5++;
        if(c3!=3 && c5!= 5)
            printf("%d", i);
        if(c3 == 3){
            printf("buzz");
            c3 = 0;
        }  
        if(c5 == 5){
            printf("fizz");
            c5 = 0;
        }
        printf("\n");            
    }
    return 0;
}