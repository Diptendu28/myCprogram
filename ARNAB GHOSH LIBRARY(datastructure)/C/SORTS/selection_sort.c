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

void SelectionSort(int *arr, int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(i != min){
            swap(&arr[i], &arr[min]);
        }

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
            SelectionSort(arr, size);
            printf("\n");
    }
    free(arr);
    system("pause");
}
