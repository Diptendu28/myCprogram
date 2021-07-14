#include<stdio.h>
#include<stdlib.h>
#include"printIO.h"

int** createMatrix(int **arr, int row, int col){
    arr = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        arr[i] = (int*)calloc(col, sizeof(int));
    }
    if(arr == NULL){
        printf("Memory not allocated!!!");
        return NULL;
    }
    return arr;
}


void freeMemory(int **arr, int row){
    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
}


void efficientSparse(int **sm, int row, int col){
    int k, counter = 0, **esm;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &sm[i][j]);
            if(sm[i][j] != 0){
                counter++;
            }
        }
    }
      
    esm = createMatrix(esm, counter+1, 3);
    esm[0][0] = row;
    esm[0][1] = col;
    esm[0][2] = counter;
    k = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(sm[i][j] != 0){
                esm[k][0] = i;
                esm[k][1] = j;
                esm[k][2] = sm[i][j];
                k++;
            }
        }
    }
    for(int i = 0; i < counter + 1; i++){
        printf("%d\t%d\t%d\n", esm[i][0],esm[i][1],esm[i][2]);
    }
    freeMemory(esm, counter+1);
}

int main(void){
    OpenIO(fopen("efficient_sparse.c", "a"));
    int **sm, row, col;
    scanf("%d%d", &row, &col);
    sm = createMatrix(sm, row, col);
    efficientSparse(sm, row, col);
    freeMemory(sm, row);
    return 0;
}

/*

input:
4 4
0  2  0  0
5  0  0  0
0  0  0  3
0  0  7  0

output:
4	4	4
0	1	2
1	0	5
2	3	3
3	2	7

*/