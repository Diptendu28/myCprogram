#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b

void printArr(int *arr, int size){
    for(int i = size-1; i >=0; i--){
       printf("%d(x^%d)",*(arr + i),i);
       if(i != 0){
        printf(" + ");
       }
    }
}

void addPoly(int *a, int *b, int sizeB){ //sizeA > sizeB
    int i = 0;
    while(i < sizeB){
        *(a+i) += *(b+i);
        i++;
    }
}

int main(void){
    int *a, *b, *c;
    int sizeA, sizeB, sizeC;
    printf("Enter the max exponent of the 1st pol: ");
    scanf("%d", &sizeA);
    printf("Enter the max exponent of the 2nd pol: ");
    scanf("%d", &sizeB);
    sizeA++;
    sizeB++;
    sizeC = max(sizeA, sizeB);

    a = (int*)calloc(sizeA, sizeof(int));
    b = (int*)calloc(sizeB, sizeof(int));
    c = (int*)calloc(sizeC, sizeof(int));

    printf("Enter %d elements in the 1st array:\n", sizeA);
    for(int i = 0; i < sizeA; i++){
        scanf("%d",(a + i));
    }

    printf("Enter %d elements in the 2nd array:\n", sizeB);
    for(int i = 0; i < sizeB; i++){
        scanf("%d",(b + i));
    }

    printf("The %d elements of 1st polynomial:\n",sizeA);
    printArr(a, sizeA);
    printf("\nThe %d elements of 2nd polynomial:\n",sizeB);
    printArr(b, sizeB);

    if(sizeC == sizeA){
        c = (int*)realloc(a, sizeC*sizeof(int));
        addPoly(c,b,sizeB);
    }
    else{
        c = (int*)realloc(b, sizeC*sizeof(int));
        addPoly(c,a,sizeA);
    }

    printf("\nThe %d elements of the final polynomial:\n",sizeC);
    printArr(c, sizeC);

    return 0;
}
