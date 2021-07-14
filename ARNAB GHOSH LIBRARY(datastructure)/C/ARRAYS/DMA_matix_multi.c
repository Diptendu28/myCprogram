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


int** multiplyMatrices(int **a, int **b, int **mat, 
                    int row1, int col1,int col2) {
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            for(int k = 0; k < col1; k++) {
                mat[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return mat;
}



int main(void) {

    int **a, row1, col1;
    int **b, row2, col2;
    int **ans;

    printf("First Matrix:\n");
    printf("Row: ");
    scanf("%d", &row1);
    printf("Col: ");
    scanf("%d", &col1);

    printf("\nSecond Matrix:\n");
    printf("Row: ");
    scanf("%d", &row2);
    printf("Col: ");
    scanf("%d", &col2);
    
    while (col1 != row2) {
        printf("\nInvalid row and col entry:\n");
        printf("First Matrix:\n");
        printf("Row: ");
        scanf("%d", &row1);
        printf("Col: ");
        scanf("%d", &col1);

        printf("\nSecond Matrix:\n");
        printf("Row: ");
        scanf("%d", &row2);
        printf("Col: ");
        scanf("%d", &col2);
    }
    

    a = createMatrix(a, row1, col1);
    b = createMatrix(b, row2, col2);
    ans = createMatrix(ans, row1, col2);

    printf("\nInsert %d elements in 1st matrix:\n", row1*col1);
    insertElements(a, row1, col1);
    printf("\nInsert %d elements in 2nd matrix:\n", row2*col2);
    insertElements(b, row2, col2);
    printf("The %d elements in 1st matrix:\n", row2*col2);
    printMatrix(a, row1,col1);
    printf("The %d elements in 2nd matrix:\n", row2*col2);
    printMatrix(b, row2, col2);
    ans = multiplyMatrices(a, b, ans, row1, col1, col2);
    printf("The %d elements after multiplication :\n", row2*col2);
    printMatrix(ans, row1, col2);
    freeMemory(a, row1);
    freeMemory(b, row2);
    freeMemory(ans, row1);

    return 0;

}


