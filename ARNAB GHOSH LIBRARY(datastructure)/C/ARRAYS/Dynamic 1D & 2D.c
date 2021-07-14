#include<stdio.h>
#include<stdlib.h>
int main(void){
    int row, col, **arr2D;
    printf("Enter the size of 2D array:\n");
    printf("ROW: ");
    scanf("%d",&row);
    printf("COL: ");
    scanf("%d",&col);

    arr2D = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        arr2D[i] = (int*)calloc(col, sizeof(int));
    }

    printf("Enter %d array elements\n",row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr2D[i][j]); //(*(arr2D + i)+j)
        }
    }

    printf("The %d elements are: \n", row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr2D[i][j]); //(*(arr2D + i)+j)
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
        free(arr2D[i]);

    free(arr2D);
    return 0;
}













/*    int *arr1D, **arr2D;
    int size1D, row, col;
/*
    printf("Enter the size of 1D array: ");
    scanf("%d",&size1D);
    arr1D = (int*)calloc(size1D, sizeof(int));
    printf("Enter the %d element(s):\n", size1D);
    for(int i = 0; i < size1D; i++){
        scanf("%d",&arr1D[i]);
    }
    printf("The %d element(s):\n", size1D);
    for(int i = 0; i < size1D; i++){
        printf("%d ",arr1D[i]);
    }

    //free(arr1D);
*/
/*
    printf("Enter the size of 2D array:\n");
    printf("ROW: ");
    scanf("%d",&row);
    printf("COL: ");
    scanf("%d",&col);

    arr2D = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        arr2D[i] = (int*)calloc(col, sizeof(int));
    }

    printf("Enter %d array elements\n",row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr2D[i][j]); //(*(arr2D + i)+j)
        }
    }

    printf("The %d elements are: \n", row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr2D[i][j]); //(*(arr2D + i)+j)
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
        free(arr2D[i]);

    free(arr2D);
*/
/*
//int ptr;
    //int (*ptr)[3];//ptr is pointer that can point to an array of 3 integers
    int arr[3]={10,20,30};
    //ptr = arr;
    //ptr = &arr;
    //ptr = &arr[0];
    int (*ptr)[3] = &arr;
    printf("%d\n",**ptr);
    printf("%d\n",*ptr);
    printf("%d\n",ptr);
    printf("%d\n",&arr);*/
