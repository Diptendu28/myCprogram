/*write a program to read matrix of size m*n from keyboard and display same on the screen.
while you write a program make the row parameter as default argument*/
#include<bits/stdc++.h>
using namespace std;

class Matrix{
private:
    int **arr;
public:
    void createMatrix(int col, int row = 3) {
        arr = (int*)calloc(row, sizeof(int));
        for(int i = 0; i < row; i++) {
            arr[i] = (int*)calloc(col, sizeof(int));
        }
        if(arr == NULL) 
            printf("Can't allocate memory");
    }

    void freeMemory(int row = 3){
        for (int i = 0; i < row; i++) {
            free(arr[i]);
        }
        free(arr);    
    }

    void printMatrix(int col, int row = 3) {
        int i,j;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    void insertElements(int col, int row = 3) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++){
                scanf("%d", &arr[i][j]); 
            }          
        }   
    }
};

int main(void){
    Matrix mat;
    int row, col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;
    mat.createMatrix(row, col);
    cout <<"Insert " << row*col <<" elements where"<< endl <<"row: "<< row << endl <<"col: "<< col <<endl;
    mat.insertElements(row, col);
    cout << "The "<<row << " x " << col << " matrix is given:"<<endl;
    mat.printMatrix(row, col);
    mat.freeMemory(row);
    return 0;
}
