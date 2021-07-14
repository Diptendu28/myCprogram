#include<stdio.h>
#include<stdlib.h>

void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void display(int *arr, int n){
    printf("\nElements in array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void InsertionSort(int *arr, int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    display(arr, n);

}


int main(){
    int *arr, size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));
    if(arr == NULL)
        printf("Menory not allocated!!!");
    else{
            printf("Enter the elemnts in stack: \n");
            for(int i = 0; i < size; i++){
                scanf("%d", &arr[i]);
            }
            printf("Before sorting: ");
            display(arr, size);
            printf("\nAfter sorting: ");
            InsertionSort(arr, size);
    }
    free(arr);
}
