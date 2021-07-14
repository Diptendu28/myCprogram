#include<Stdio.h>
#include<stdlib.h>
int main(void){
    int* ptr;
    int ele, pos;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    ptr = (int*)calloc(size, sizeof(int));

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


    // reallocating the memory
    size++;
    ptr = (int*)realloc(ptr, size*sizeof(int));
    printf("\nEnter the position(between 1 to %d): ",size);
    scanf("%d", &pos);

    if(pos > size || pos < 0){
        printf("Position is not valid");
        exit(0);
    }

    printf("Enter the new element: ");
    scanf("%d", &ele);
    for(int i = size - 1; i >= pos-1; i--){
        *(ptr + i + 1) = *(ptr + i);
    }
    *(ptr + pos - 1) = ele;
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d ",*(ptr + i));
    }
    // free the memory
    free(ptr);
    return 0;
}
