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


int main(void) {

    int **a, row1, col1;
    int **b, row2, col2;
    
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
    
    a = createMatrix(a, row1, col1);
    b = createMatrix(b, row2, col2);
    printf("Insert %d elements in 1st matrix:\n", row1*col1);
    insertElements(a, row1, col1);
    printf("Insert %d elements in 2nd matrix:\n", row2*col2);
    insertElements(b, row2, col2);
    printf("The %d elements in 1st matrix:\n", row2*col2);
    printMatrix(a, row1,col1);
    printf("The %d elements in 2nd matrix:\n", row2*col2);
    printMatrix(b, row2, col2);
    freeMemory(a, row1);
    freeMemory(b, row2);

    return 0;

}


// int arr[i][j] == int **arr(value with i and j)
// arr[i][j]; -> *(*(arr + i) + j), i->row, j->col
// arr[i][j] -> for static -> 2 index represent 1 elements
//  [
//   arr = (int**)calloc(row, sizeof(int*)); == arr[i][?], j is unknown
//   for(int i = 0; i < row; i++) {
//       arr[i] = (int*)calloc(col, sizeof(int)); == == arr[i][j]
//   }
//  ] -> for dynamic -> 2 pointes represent 1 elements where i = row pointer, j = col / element pointer
//          arr   -> points to 0th 1D array
//         *arr   -> points to 0th element of 0th 1D array -> value at the address of 0th 1D array
//      (arr+i)   -> points to ith 1D array
//      *(arr+i)  -> points to 0th element of ith 1D array -> value at the address of 0th element of ith 1D array -> address of 0th element of ith 1D array
//  (*(arr+i)+j)  -> points to jth element of ith 1D array -> value at the address of jth element of ith 1D array -> address of jth element of ith 1D array
// *(*(arr+i)+j)  -> value of jth element of ith 1D array
