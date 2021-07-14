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

int** multiMat(int **a, int **b, int **ans, int row1, int col1, int row2, int col2){
   for (int i = 0; i < row1; ++i){
      for (int j = 0; j < col2; ++j){
         for (int k = 0; k < col1; ++k){
            ans[i][j] += a[i][k] * b[k][j];
         }
      }
   }
   return ans;
}


int main(void){
    //OpenIO(fopen("transpose_of_efficient_sparce.c", "a"));
    int **a, **b, **ans, row1, col1, row2, col2;

   printf("Enter size of 1st matrix:\n");
   printf("Rows: ");
   scanf("%d",&row1);
   printf("Columns: ");
   scanf("%d",&col1); 

   printf("Enter size of 2nd matrix:\n");
   printf("Rows: ");
   scanf("%d",&row2);
   printf("Columns: ");
   scanf("%d",&col2);

   while (col1 != row2) {
       printf("Invalid Row and Column entry!!!\n");
       printf("Enter size of 1st matrix:\n");
       printf("Rows: ");
       scanf("%d",&row1);
       printf("Columns: ");
       scanf("%d",&col1);

       printf("Enter size of 2nd matrix:\n");
       printf("Rows: ");
       scanf("%d",&row2);
       printf("Columns: ");
       scanf("%d",&col2);
   }
   
   a = createMatrix(a, row1, col1);
   printf("Insert Elements in 1st Matrix\n");
   insertElements(a, row1, col1); 
   
   b = createMatrix(b, row2, col2);
   printf("Insert Elements in 2nd Matrix\n");
   insertElements(b, row2, col2); 
  
   ans = createMatrix(ans, row1, col2);
   ans = multiMat(a, b, ans, row1, col1, row2, col2); 

   printf("The 1st matrix is:\n");
   printMatrix(a, row1, col1); 
   printf("The 2nd matrix is:\n");
   printMatrix(b, row2, col2); 
   printf("The resultant matrix is:\n");
   printMatrix(ans, row1, col2);

   freeMemory(a, row1);
   freeMemory(b, row2);
   freeMemory(ans,row1);
   return 0;
}

/*
Enter size of 1st matrix:
Rows: 2
Columns: 3
Enter size of 2nd matrix:
Rows: 3
Columns: 4
Insert Elements in 1st Matrix
2 1 4
0 1 1
Insert Elements in 2nd Matrix
6 3 -1 0
1 1 0 4
-2 5 0 2
The 1st matrix is:
2  1  4
0  1  1
The 2nd matrix is:
6  3  -1  0
1  1  0  4
-2  5  0  2
The resultant matrix is:
5  27  -2  12
-1  6  0  6
*/