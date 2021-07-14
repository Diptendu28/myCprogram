#include<Stdio.h>
#include<stdlib.h>
int main(void){
    int* ptr;
    int* temp;
    int key, counter = 0, j = 0;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    ptr = (int*)calloc(size, sizeof(int));
    temp = (int*)calloc(size, sizeof(int));

    // if memory not allocated
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Take array input
    printf("Enter the %d element(s):\n", size);
    for(int i = 0; i < size; i++){
        scanf("%d",(ptr + i));
    }
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d ",*(ptr + i));
    }

    // Take input to delete the element
    printf("\nEnter the value to delete from array: ");
    scanf("%d",&key);

    for(int i = 0; i < size; i++){
        if(*(ptr + i) != key){
            *(temp + j) = *(ptr + i);
            j++;
            counter++;
        }
    }

    // if element is not in the array
    if(counter == size){
        printf("Element %d not found.\n", key);
        printf("The %d element(s) are:\n", size);
        for(int i = 0; i < size; i++){
            printf("%d ",*(ptr + i));
        }
    }
    else {
        size = counter;
        ptr = (int*)realloc(temp, size * sizeof(int));
        // Print all the elements
        printf("The %d element(s) are:\n", size);
        for(int i = 0; i < size; i++){
            printf("%d ",*(ptr + i));
        }

    }
    // free the memory
    free(ptr);
    free(temp);
    return 0;
}
