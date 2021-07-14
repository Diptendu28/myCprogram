#include<stdio.h>
#include<stdlib.h>
#include"printIO.h"

int** createMatrix(int **arr, int row, int col){
    arr = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        arr[i] = (int*)calloc(col, sizeof(int));
    }
    return arr;
}

void insertElements(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d",&arr[i][j]);               
        }
    }
}


void freeMemory(int **arr, int row){
   for(int i = 0; i < row; i++){
        free(arr[i]);
    }    
    free(arr);
}

int** transposeMatrix(int **arr, int *row, int *col){
    int **temp = createMatrix(temp,*col, *row);
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            temp[j][i] = arr[i][j];
        }
    }
    // swap row and col
    if(*row != *col){
        *row = *row ^ *col;
        *col = *row ^ *col;
        *row = *row ^ *col;
    }
    return temp;
}



void printMatrix(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j =0; j < col; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}


int main(void){   
    OpenIO(fopen("test.c","a"));
    int **arr;
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    arr = createMatrix(arr, row, col);
    insertElements(arr, row, col);
    printMatrix(arr, row, col);
    arr = transposeMatrix(arr, &row, &col);
    printf("\n\n");
    printMatrix(arr, row, col);
    freeMemory(arr, row);
    return 0; 
}

/*
input:
3 2

1 2
3 4
5 6

output:
1  2  
3  4  
5  6  


1  3  5  
2  4  6  


*/