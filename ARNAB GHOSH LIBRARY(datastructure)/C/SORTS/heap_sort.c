#include<stdio.h>
#include<stdlib.h>

void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


void heapify(int *arr, int size, int i){
    int max = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < size && arr[l] > arr[max])
        max = l;
    if (r < size && arr[r] > arr[max])
        max = r;
    if (max != i){
        swap(&arr[i], &arr[max]);
        heapify(arr, size, max);
    }
}
 

void heap_sort(int *arr, int size){
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(arr,size, i);
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void display(int *arr, int size){
    printf("\nElements in array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}


int main(void){
    int *arr, size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL)
        printf("Menory not allocated!!!");
    else{
        printf("Enter the elemnts in array: \n");
        for(int i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }
        printf("Before sorting: ");
        display(arr, size);
        printf("\nAfter sorting: ");
        heap_sort(arr, size);
        display(arr, size);
    }
    free(arr);
    return 0;
}

/*

Enter the size of array: 7
Enter the elemnts in array: 
113 -5 58 21 74 1 45
Before sorting:
Elements in array: 113 -5 58 21 74 1 45
After sorting:
Elements in array: -5 1 21 45 58 74 113

*/