#include<stdio.h>
#include<stdlib.h>

int** createMatrix(int **arr, int row, int col) {
    arr = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++) {
        arr[i] = (int*)calloc(col, sizeof(int));
    }
    if(arr == NULL) {
        printf("Can't allocate memory");
        return 0;
    }
    return arr;
}


void insertElements(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]); 
        }          
    }   
}


void printMatrix(int **arr, int row, int col) {
    int i,j;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void freeMemory(int **arr, int row){
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);    
}


void getUpper (int **arr, int row, int col) {
    printf("\nThe Upper Triangular Part:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(j >= i) {
                printf("%d ", arr[i][j]);
            }
            else { 
                printf("0 ");
            }
        }
        printf("\n");
    }       
}


void getLower(int **arr, int row, int col) {
    printf("\nThe Lower Triangular Part:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i >= j) {
                printf("%d ", arr[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }        
}


int main(void) {
    int **mat;
    int row, col;

    printf("Fill the Matrix:\n");
    printf("Row: ");
    scanf("%d", &row);
    printf("Col: ");
    scanf("%d", &col);

    mat = createMatrix(mat, row, col);
    printf("Insert %d elements in the Matrix:\n", row*col);
    insertElements(mat, row, col);
    getUpper(mat, row, col);
    getLower(mat, row, col);
    printf("\nThe Original Matrix:\n");
    printMatrix(mat, row,col);
    freeMemory(mat, row);

    return 0;
}