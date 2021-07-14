#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr, int size){
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
        count[arr[i]]++;

    for(int i = 1; i <= max; i++)
        count[i]+= count[i-1];

    for(int i = size - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = output[i];
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
    countSort(arr, size);
    printf("\n\nThe elements after sorting:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

/*
Output - 1
-------------
Enter the number of elements: 7
Enter 7 elements int the array:
arr[0]: 78
arr[1]: 5 
arr[2]: 44
arr[3]: 64
arr[4]: 10
arr[5]: 7
arr[6]: 56

The elements before sorting:
78 5 44 64 10 7 56

The elements after sorting:
5 7 10 44 56 64 78


Output - 2
-------------
Enter the number of elements: 5
Enter 5 elements int the array:
arr[0]: 7        
arr[1]: 5
arr[2]: 7
arr[3]: 9
arr[4]: 2

The elements before sorting:
7 5 7 9 2 

The elements after sorting:
2 5 7 7 9 

*/