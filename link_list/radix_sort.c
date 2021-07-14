#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr, int size, int e){
    int *output, *count, max;
	int i;
    max = arr[0];

    for( i = 1; i < size; i++)
        if(max < arr[i])
            max = arr[i];

    count = (int*)malloc(max*sizeof(int));
    output = (int*)malloc(size*sizeof(int));

    for( i = 0; i <= max; i++)
        count[i] = 0;

    for( i = 0; i < size; i++)
        count[(arr[i]/e)%10]++;

    for( i = 1; i <= max; i++)
        count[i]+= count[i-1];

    for( i = size - 1; i >= 0; i--){
        output[count[(arr[i]/e)%10] - 1] = arr[i];
        count[(arr[i]/e)%10]--;
    }

    for( i = 0; i < size; i++)
        arr[i] = output[i];
}



void radixSort(int *arr, int size){
    int m,i,e;
    int max = arr[0];

    for(i = 1; i < size; i++)
        if(max < arr[i])
            max = arr[i];

    for(e = 1; m/e > 0; e *= 10)
        countSort(arr, size, e);
}



int main(void){
    int *arr, size,i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    arr = (int*)malloc(size*sizeof(int));
    printf("Enter %d elements int the array:\n", size);
    for( i = 0; i < size; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("The elements before sorting:\n");
    for( i = 0; i < size; i++)
        printf("%d ", arr[i]);
    radixSort(arr, size);
    printf("\n\nThe elements after sorting:\n");
    for( i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
