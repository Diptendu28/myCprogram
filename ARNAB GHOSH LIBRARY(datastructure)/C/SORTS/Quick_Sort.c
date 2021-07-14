#include<stdio.h>
#include<stdlib.h>

void insertElements(int *arr, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
  int temp = *a;
    *a = *b;
    *b = temp;
}


int partion(int *arr, int l, int h){
    int pivot, i, j;
    pivot = arr[h];
    i = l - 1;
    for(j = l; j <= h-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i + 1;
}

void quickSort(int *arr, int l, int h){
    if(l < h){
        int p = partion(arr, l,h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

int main(){
    int *arr, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int));
    if(arr == NULL){
        printf("Can't Allocate Memory");
        exit(0);
    }
    printf("Insert Elements in Array:\n");
    insertElements(arr, size);

    printf("Array Before Sorting:\n");
    printArray(arr, size);   

    quickSort(arr, 0, size-1);

    printf("Array After Sorting:\n");
    printArray(arr, size);    

    return 0;
}

