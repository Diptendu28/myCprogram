#include<stdio.h>
void addMatrix(int a[100][100], int b[100][100],int c[100][100], int row, int col){
    // addition operation
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    // print final matrix
    printf("\nThe %d elements of final matrix:\n", row*col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
           printf("%d ", c[i][j]);
        printf("\n");
    }

}


int main(void){
    int a[100][100],b[100][100],c[100][100];
    int row, col;
    printf("enter the number rows: ");
    scanf("%d",&row);
    printf("enter the matrix columns: ");
    scanf("%d",&col);

    printf("Enter the %d elements of 1st matrix:\n", row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            scanf("%d",&a[i][j]);
     }

    printf("Enter the %d elements of 2nd matrix:\n", row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            scanf("%d",&b[i][j]);
     }

    printf("\nThe %d elements first matrix:\n", row*col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
           printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nThe %d elements second matrix:\n", row*col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
           printf("%d ", b[i][j]);
        printf("\n");
    }

    addMatrix(a,b,c,row,col); // perform the addition operation

    return 0;
}

