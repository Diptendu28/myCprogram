THIS CODE IS NOT COMPLETED YET

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
        printf("%d\n",*(ptr + i));
    }


    // reallocating the memory
    size++;
    ptr = (int*)realloc(ptr, size*sizeof(int));
    printf("Enter the position(between 1 to %d): ",size);
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
        printf("%d\n",*(ptr + i));
    }
    // free the memory
    free(ptr);
    return 0;
}

/*
The 5 element(s) are:
1
2
3
4
5
Enter the new element: 9
Enter the position: 6
The 6 element(s) are:
1
2
3
4
5
9
*/


/*
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

    size = counter;
    ptr = (int*)realloc(temp, size * sizeof(int));

    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d ",*(ptr + i));
    }
    // free the memory
    free(ptr);
    free(temp);
    return 0;
}






/*
1 2 1 2 3 1 2 2 1 5
2 2 3 1 2 3 4 1 2 2

Enter the size: 10
Enter the 10 element(s):
1 2 3 1 2 3 4 1 2 2
The 10 element(s) are:
1 2 3 1 2 3 4 1 2 2
Enter the value to delete from array: 2
The 7 element(s) are:
1 3 1 3 4 1 2*/

/**
all algorithms:
------------------
1) Traversing
// Traverse Operation - ASC
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d\n",*(ptr + i));
    }

// Traverse Operation - DSC
    printf("\nThe %d element(s) are:\n", size);
    for(int i = (size - 1); i >= 0; i--){
        printf("%d\n",*(ptr + i));
    }

2) insert element at front
-------------------------------
#include<Stdio.h>
#include<stdlib.h>
int main(void){
    int* ptr;
    int ele;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    ptr = (int*)calloc(size, sizeof(int));
    if (ptr == NULL) { // if memory not allocated
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
        printf("%d\n",*(ptr + i));
    }


    // reallocating the memory
    size++;
    ptr = (int*)realloc(ptr, size*sizeof(int));
    printf("Enter the new elements to insert at front: ");
    scanf("%d", &ele);
    for(int i = size - 1; i >= 0; i--){
        *(ptr + i + 1) = *(ptr + i); //*(ptr + i + 1) = *(ptr + i);
    }
    *ptr = ele;
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d\n",*(ptr + i));
    }
    // free the memory
    free(ptr);
    return 0;
}

3) insert element at end
--------------------------
#include<Stdio.h>
#include<stdlib.h>
int main(void){
    int* ptr;
    int ele;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    ptr = (int*)calloc(size, sizeof(int));
    if (ptr == NULL) { // if memory not allocated
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
        printf("%d\n",*(ptr + i));
    }


    // reallocating the memory
    size++;
    ptr = (int*)realloc(ptr, size*sizeof(int));
    printf("Enter the new elements to insert at end: ");
    scanf("%d", &ele);
    *(ptr + size-1) = ele;
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d\n",*(ptr + i));
    }
    // free the memory
    free(ptr);
    return 0;
}


4) element at particular pos:
-------------------------------
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
        printf("%d\n",*(ptr + i));
    }


    // reallocating the memory
    size++;
    ptr = (int*)realloc(ptr, size*sizeof(int));
    printf("Enter the new element: ");
    scanf("%d", &ele);
    printf("Enter the position: ");
    scanf("%d", &pos);
    for(int i = size - 1; i >= pos-1; i--){
        *(ptr + i + 1) = *(ptr + i);
    }
    *(ptr + pos - 1) = ele;
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d\n",*(ptr + i));
    }
    // free the memory
    free(ptr);
    return 0;
}

*/
/* Reallocation of memory
// reallocating the memory
    printf("Enter the new size: ");
    scanf("%d",&size);
    ptr = (int*)realloc(ptr, size*sizeof(int));

    // Take array input
    printf("Enter the %d element(s):\n", size);
    for(int i = 0; i < size; i++){
        scanf("%d",(ptr + i));
    }
    // Print all the elements
    printf("The %d element(s) are:\n", size);
    for(int i = 0; i < size; i++){
        printf("%d\n",*(ptr + i));
    }
*/
/*

Type - 1
-----------
rule 1:
        for(i = 0; i < n; i++) {
        printf("%d",*(ptr + i));    ptr -> base address and not constant
        }
rule 2:
        for(i = 0; i < n; i++) {
        printf("%d",*(&i[ptr]));
        }
rule 3:
        for(i = 0; i < n; i++) {
        printf("%d",*(&ptr[i]));
        }
rule 4:
        for(i = 0; i < n; i++) {
        printf("%d",*ptr);
        ptr++;
        }


Type - 2
----------
rule 1:
        for(i = 0; i < n; i++) {
        printf("%d",*(arr + i)); arr -> base address and constant
        }
rule 2:
        for(i = 0; i < n; i++) {
        printf("%d",*(&arr[i]));
        }
rule 3:
        for(i = 0; i < n; i++) {
        printf("%d",*(&i[arr]));
        }

*/
