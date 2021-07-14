#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr, int size, int e){
    int *output, *count, max;

    max = arr[0];

    for(int i = 1; i < size; i++)
        if(max < arr[i])
            max = arr[i];

    count = (int*)malloc(max*sizeof(int));
    output = (int*)malloc(size*sizeof(int));

    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(int i = 0; i < size; i++)
        count[(arr[i]/e)%10]++;

    for(int i = 1; i <= max; i++)
        count[i]+= count[i-1];

    for(int i = size - 1; i >= 0; i--){
        output[count[(arr[i]/e)%10] - 1] = arr[i];
        count[(arr[i]/e)%10]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = output[i];
}



void radixSort(int *arr, int size){
    int m, e;
    int max = arr[0];

    for(int i = 1; i < size; i++)
        if(max < arr[i])
            max = arr[i];

    for(e = 1; m/e > 0; e *= 10)
        countSort(arr, size, e);
}



int main(void){
    int *arr, size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    arr = (int*)malloc(size*sizeof(int));
    printf("Enter %d elements int the array:\n", size);
    for(int i = 0; i < size; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("The elements before sorting:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    radixSort(arr, size);
    printf("\n\nThe elements after sorting:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
/*

output - 1
-------------
Enter the number of elements: 6 
Enter 6 elements int the array:
arr[0]: 754
arr[1]: 852
arr[2]: 912
arr[3]: 754
arr[4]: 753
arr[5]: 123

The elements before sorting:
754 852 912 754 753 123 

The elements after sorting:
123 753 754 754 852 912 

output - 2
-------------
Enter the number of elements: 5
Enter 5 elements int the array:
arr[0]: 777
arr[1]: 444
arr[2]: 555
arr[3]: 11
arr[4]: 200

The elements before sorting:
777 444 555 11 200

The elements after sorting:
11 200 444 555 777

*/