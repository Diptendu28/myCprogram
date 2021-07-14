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

void freeMemory(int **arr, int row){
   for(int i = 0; i < row; i++){
        free(arr[i]);
    }    
    free(arr);
}
void checkSparce(int **arr, int row, int col){
    int counter = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                counter++;
            }                
        }
    }
    if(counter > (row*col)/2){
        printf("Yes");
    }
    else{
        printf("No");
    }       
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
    checkSparce(arr, row, col);
    printf("\n");
    printMatrix(arr, row, col);
    freeMemory(arr, row);
    return 0; 
}
