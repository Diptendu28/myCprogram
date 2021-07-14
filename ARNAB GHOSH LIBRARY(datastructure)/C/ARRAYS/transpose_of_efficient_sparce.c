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


void insertElements(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d",&arr[i][j]);               
        }
    }
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
        for(int j = 0; j < col; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
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
    printf("\n"); 
}



int** efficientSparse(int **sm, int **esm, int row, int col, int *E_row){
    int k, counter = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
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

    *E_row = counter+1;
    return esm;
}

int** transposeEfficientSparse(int **T_esm, int **esm, int row){
    T_esm = createMatrix(T_esm, row, 3);
    T_esm[0][0] = esm[0][1];
    T_esm[0][1] = esm[0][0];
    T_esm[0][2] = esm[0][2];
    int k = 1;
    for(int i = 0; i < row - 1; i++){
        for(int j = 1; j <= esm[0][2]; j++){
            if(esm[j][1] == i){
                T_esm[k][0] = esm[j][1];
                T_esm[k][1] = esm[j][0];
                T_esm[k][2] = esm[j][2];
                k++;
            }
        }
    }    
    return T_esm;    
}

int main(void){
    OpenIO(fopen("transpose_of_efficient_sparce.c", "a"));
    int **sm, row, col;
    int **esm, E_row, E_col = 3;
    int **T_esm;
    int **trans_sm;

    scanf("%d%d", &row, &col);
    sm = createMatrix(sm, row, col);
    insertElements(sm, row, col);
    printf("The Matrix is: \n");
    printMatrix(sm, row, col); 
    printf("\n");

    printf("is it a sparse matrix ? \n");
    checkSparce(sm, row, col);
    printf("\n");

    printf("The Efficient Sparse repesentation of Matrix is: \n");
    esm = efficientSparse(sm, esm, row, col, &E_row);
    printMatrix(esm, E_row, E_col);
    printf("\n");
    
    printf("The Transpose of Efficient Sparse repesentation of Matrix is: \n");
    T_esm = transposeEfficientSparse(T_esm, esm, E_row);
    printMatrix(T_esm, E_row, E_col);
    printf("\n");

    printf("The Transpose of Matrix is: \n");
    trans_sm = transposeMatrix(sm, &row, &col);
    printMatrix(trans_sm, row, col);
    printf("\n");

    printf("is the transpose of that matrix a sparse matrix ? \n");
    checkSparce(trans_sm, row, col);
    printf("\n");

    printf("The Efficient Sparse repesentation of Transpose of Matrix is: \n");
    esm = efficientSparse(trans_sm, esm, row, col, &E_row);
    printMatrix(esm, E_row, E_col);
    printf("\n");
    
    printf("The Transpose of Efficient Sparse repesentation of Transpose of Matrix is: \n");
    T_esm = transposeEfficientSparse(T_esm, esm, E_row);
    printMatrix(T_esm, E_row, E_col);

    freeMemory(sm, row);
    freeMemory(esm, E_row);
    freeMemory(T_esm, E_row);
    return 0;
}

/*
The Matrix is: 
0  2  0  0  
5  0  0  0  
0  0  0  3  
0  0  7  0  

is it a sparse matrix ? 
Yes

The Efficient Sparse repesentation of Matrix is: 
4  4  4  
0  1  2  
1  0  5  
2  3  3  
3  2  7  

The Transpose of Efficient Sparse repesentation of Matrix is: 
4  4  4  
0  1  5  
1  0  2  
2  3  7  
3  2  3  

The Transpose of Matrix is: 
0  5  0  0  
2  0  0  0  
0  0  0  7  
0  0  3  0  

is the transpose of that matrix a sparse matrix ? 
Yes

The Efficient Sparse repesentation of Transpose of Matrix is: 
4  4  4  
0  1  5  
1  0  2  
2  3  7  
3  2  3  

The Transpose of Efficient Sparse repesentation of Transpose of Matrix is: 
4  4  4  
0  1  2  
1  0  5  
2  3  3  
3  2  7  
 
*/