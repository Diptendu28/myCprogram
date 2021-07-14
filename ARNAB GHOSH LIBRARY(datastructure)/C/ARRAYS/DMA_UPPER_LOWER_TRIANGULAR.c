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



void freeMemory(int **arr, int row){
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);    
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

void insertElements(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]); 
        }          
    }   
}

int isUpper(int **arr, int row) {
    int i,j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < i; j++) {
            if(arr[i][j] != 0) {
                return 0;
                break;
            }
        }
    }
    if(i == row) {
        return 1;
    }
    
}

int isLower(int **arr, int row, int col) {
    int i,j;
    for(i = 0; i < row; i++) {
        for(j = col - 1; j > i; j--) {
            if(arr[i][j] != 0) {
                return 0;
                break;
            }
        }
    }
    if(i == row) {
        return 1;
    }
}

void getUpper (int **arr, int row, int col) {
    if(isUpper(arr, row)) {
        printf("\nThe Upper Triangular Part:\n");
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(j >= i) {
                    printf("%d ", arr[i][j]);
                }
                else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }    
}

void getLower(int **arr, int row, int col) {
    if(isLower(arr, row, col)) {
        printf("\nThe Lower Triangular Part:\n");
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i >= j) {
                    printf("%d ", arr[i][j]);
                }
            }
            printf("\n");
        }
    }    
}

int main(void) {
    int **mat;
    int row, col, flag;

    printf("Fill the Matrix:\n");
    printf("Row: ");
    scanf("%d", &row);
    printf("Col: ");
    scanf("%d", &col);

    mat = createMatrix(mat, row, col);
    printf("Insert %d elements in the Matrix:\n", row*col);
    insertElements(mat, row, col);
    flag = isUpper(mat, row);
    if(flag) {
        printf("Upper Triangle Matrix\n");
    }
    flag = isLower(mat, row, col);
    if(flag) {
        printf("Lower Triangle Matrix\n");
    }
    getUpper(mat, row, col);
    getLower(mat, row, col);
    printf("\nThe Original Matrix:\n");
    printMatrix(mat, row,col);
    freeMemory(mat, row);

    return 0;
}