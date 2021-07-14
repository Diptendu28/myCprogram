#include<stdio.h>
#include<stdlib.h>

int** createMatrix(int **arr, int size) {
    arr = (int**)calloc(size, sizeof(int*));
    for(int i = 0; i < size; i++) {
        arr[i] = (int*)calloc(size, sizeof(int));
    }
    if(arr == NULL) {
        printf("Can't allocate memory");
        return 0;
    }
    return arr;
}



void freeMemory(int **arr, int size){
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);   
}


void printMatrix(int **arr, int size) {    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void insertElements(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            scanf("%d", &arr[i][j]); 
        }          
    }   
}

int** doTranspose(int **a, int **aT, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            aT[j][i] = a[i][j];
        }
    }
    return aT;
}



void checkSymmetric(int **a, int **aT, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (a[i][j] != aT[i][j])
          break;
      }
      if (j != size)
        break;
    }
    if (i == size)
      printf("The matrix is symmetric.\n");
    else
      printf("The matrix is not symmetric.\n");
}
      


int main(void) {

    int **a,**aT;
    int size;

    printf("\nFill the Matrix:\n");
    printf("size: ");
    scanf("%d", &size); 

    a = createMatrix(a, size);
    aT = createMatrix(a, size);

    printf("Insert %d elements in matrix:\n", size*size);
    insertElements(a, size);

    printf("The %d elements in the Main Matrix:\n", size*size);
    printMatrix(a, size);
    aT = doTranspose(a, aT, size);
    printf("The %d elements in the Transpose of the Main Matrix:\n", size*size);
    printMatrix(aT, size);

    checkSymmetric(a, aT, size);

    freeMemory(a, size);
    freeMemory(aT, size);

    return 0;

}