#include<stdio.h>
#include<stdlib.h>
void printArray(int *arr, int size){
    printf("\nThe %d elements are:\n", size);
    for(int i = 0; i < size; i++){
       printf("%d ",*(arr + i));
    }
}

void sort(int *arr, int size){
    int temp;
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(*(arr+j)>*(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}


void merge(int *c, int *a, int *b, int sizeA, int sizeB,int sizeC){
    int i = 0, j = 0, k = 0;
    while(i<sizeA && j<sizeB){
        if(*(a+i) <= *(b+j)){
            *(c+k++) = *(a+i++);
        }
        else {
            *(c+k++) = *(b+j++);
        }
    }
    while(i<sizeA){
        *(c+k++) = *(a+i++);
    }
    while(j<sizeB){
        *(c+k++) = *(b+j++);
    }
}

int main(void){
    int *a, *b, *c;
    int sizeA, sizeB, sizeC;

    printf("Enter the size of the 1st array: ");
    scanf("%d", &sizeA);
    a = (int*)calloc(sizeA, sizeof(int));

    printf("Enter elements in the 1st array:\n");
    for(int i = 0; i < sizeA; i++){
        scanf("%d",(a + i));
    }

    printf("Enter the size of the 2nd array: ");
    scanf("%d", &sizeB);
    b = (int*)calloc(sizeB, sizeof(int));

    printf("Enter elements in the 2nd array:\n");
    for(int i = 0; i < sizeB; i++){
        scanf("%d",(b + i));
    }

    sizeC = sizeA + sizeB;
    c = (int*)calloc(sizeC, sizeof(int));

    sort(a,sizeA);
    sort(b, sizeB);
    merge(c,a,b,sizeA,sizeB,sizeC);
    printArray(c,sizeC);

    free(a);
    free(b);
    free(c);
    return 0;
}
