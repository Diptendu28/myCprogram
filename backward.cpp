#include<stdio.h>
#include<stdlib.h>

// Calculating u(u-1)(u-2)...(u-n)
double u(double u, int n){
    double val = u;
    for (int i = 1; i < n; i++)
        val *= (u + i);
    return val;
}

// Calculating Factorial
int fact(int n){
    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}


int main(void){
    
    double *x, **y, sum, u, num, h;
    int size, nabla = 31;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // 1d array
    x = (double*)malloc(size*sizeof(double)); 

    // 2d array
    y = (double**)malloc(size*sizeof(double)); 
    for(int i = 0; i < size; i++)
        y[i] = (double*)malloc(size*sizeof(double));

    // Taking Inputs
    printf("\nEnter the data\n");
    for(int i = 0; i < size; i++){
        printf("X%d=",i+1);
        scanf("%lf", &x[i]);
        printf("Y%d=",i+1);
        scanf("%lf", &y[i][0]);
    }

    // Calculating the Backward Difference Table
    for(int col = 1; col < size; col++)
        for(int row = size-1; row >= col; row--)
            y[row][col] = y[row][col-1] - y[row-1][col-1];


    // Display the Table Header of Backward Difference Table
    printf( "\nDifference table is:-\n");
    printf("\tX\tY");
    for(int i = 0; i <= size - 2; i++)
        printf("\t%c^%dY",nabla,i+1);
        
        
    printf("\n");

    // Display the Backward Difference Table
    for(int i = 0; i < size; i++){
        printf("\t%.0lf\t", x[i]);
        for(int j = 0; j <= i; j++)
            printf("%.2lf\t", y[i][j]);
        printf("\n");
    }
    
    // asking for f(x)
    printf("\nEnter the value x for function f(x): ");
    scanf("%lf", &num);

    sum = y[size-1][0];
    h = x[1]-x[0];
    u = (num - x[size-1]) / h;

    for (int i = 1; i < size; i++)
        sum += (_u_(u, i) * y[size-1][i]) / fact(i);   

    printf("\nthe value of function at x = %lf is %lf\n", num, sum);   

    return 0;
}
