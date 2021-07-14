THIS PROGRAM IS NOT COMPLETED YET


#include<stdio.h>
#include<stdlib.h>

void insertAtPos(int *arr, int size){
  while(1){
    printf("\n\nChoose the option ---\n");
    printf("1) at front\n2) at end\n3) at position\n4) exit\n5) display\n");
    int opt;
    printf("\nOption: ");
    scanf("%d", &opt);
    switch(opt){
      case 1:{
        size++;
        arr = (int*)realloc(arr, size*sizeof(int));
        if (arr == NULL){
            printf("Memory not allocated.\n");
            exit(0);
        }
        for(int i = size - 1; i>=0; i--){
            arr[i+1] = arr[i]; //right shift
        }
        int item;
        printf("\nEnter the item to insert: ");
        scanf("%d", &item);
        arr[0] = item;
        break;
      }
      case 2:{
        size++;
        arr = (int*)realloc(arr, size*sizeof(int));
        int item;
        printf("\nEnter the item to insert: ");
        scanf("%d", &item);
        arr[size-1] = item;
        break;
      }
      case 3:{
        size++;
        arr = (int*)realloc(arr, size*sizeof(int));
        if (arr == NULL){
            printf("Memory not allocated.\n");
            exit(0);
        }
        int pos;
        printf("\nEnter the position to insert: ");
        scanf("%d", &pos);
        if(pos>size){
            printf("Invalid position input!\n");
            printf("Must be (<=%d)", size);
            size--;
            continue;
        }
        for(int i = size - 1; i >= pos-1; i--){
            arr[i+1] = arr[i]; //right shift
        }
        int item;
        printf("\nEnter the item to insert: ");
        scanf("%d", &item);
        arr[pos-1] = item;
        break;
      }
      case 4:{
        exit(0);
        break;
      }
      case 5:{
        for(int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        break;
      }
      default: printf("Invalid Entry:"); break;
    }
  }
}




int* createArray(int *arr, int size){
  arr = (int*)calloc(size, sizeof(int));
  if(arr == NULL){
    printf("unable to allocate memory.");
  }
  return arr;
}





void insertElements(int *arr, int size){
  printf("Enter %d elements:\n", size);
  for(int i = 0; i < size; i++){
    scanf("%d",&arr[i]);
  }
}





void printArray(int *arr, int size){
  printf("The elements in array is: \n");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}





int main(void){
  int *arr;
  int size;
  printf("Enter the size of the Array: ");
  scanf("%d", &size);
  arr = createArray(arr, size);
  insertElements(arr, size);
  printArray(arr, size);
  insertAtPos(arr, size);
  free(arr);
  return 0;
}
