#include<stdio.h>
#include<stdlib.h>
int main(void){
    int dec = 0;
    printf("a  b  c  d  y  dec\n");
    printf("--------------------\n");
    for(int  a = 0; a <= 1; a++)
        for(int  b = 0; b <= 1; b++)
            for(int  c = 0; c <= 1; c++)
                for(int  d = 0; d <= 1; d++)
                    printf("%d  %d  %d  %d  %d  %d\n", a, b, c, d, !((!((!c)*b*a))*(!((!d)*c*a))*(!((!b)*c*a)))?1:0, ++dec);
    printf("\n");
    system("pause");
    return 0;
}

/**
(!((!c)*b*a))
(!((!d)*c*a))
(!((!b)*c*a))

!((!((!c)*b*a))*(!((!d)*c*a))*(!((!b)*c*a)))

*/
