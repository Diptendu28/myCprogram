#include<stdio.h>
#include<stdlib.h>

int* sort(int *array, int num){
    int temp, i, j;
    for (i = 0 ; i < num - 1; i++){
    for (j = 0 ; j < num - 1 - i; j++){
      if (array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
      }
    }
  }
  return array;
}


int binarySearch(int *arr, int l, int r, int key)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key){
            return m;
        }
        if (arr[m] < key){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

int main(void){
    int *arr;
    int size;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    arr = (int*)calloc(size, sizeof(int));
    if(arr==NULL){
        printf("Memory is not allocated");
    }

    printf("Enter elements in the array: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    arr = sort(arr, size);
    printf("The elements in array after sorting is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

   
    

    return 0;
}
