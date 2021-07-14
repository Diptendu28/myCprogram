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

void ModifiedBubbleSort(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        int flag = 0;
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag++;
            }
        }
        if(flag == 0)
            break;
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
            ModifiedBubbleSort(arr, size);
    }
    free(arr);
}
