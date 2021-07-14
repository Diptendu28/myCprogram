#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>

typedef struct Polynomials{
    int coef;
    int expo;
} poly;

poly* createPoly(poly *p, int size){
    p = (poly*)calloc(size, sizeof(poly));
    return p;
}

void insertElements(poly *p, int size){
    printf("Enter %d terms of the polynomial expression\n", size);
    for(int i = 0; i < size; i++){
        printf("Element[%d]:\n", i+1);
        printf("coef: ");
        scanf("%d", &p[i].coef);
        printf("expo: ");
        scanf("%d", &p[i].expo);
    }
    printf("\n");

}


void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


void sortPoly(poly *p, int size){
    for(int i = 0; i < size-1; i++){
        int flag = 0;
        for(int j = 0; j < size - 1 - i; j++){
            if(p[j].expo < p[j+1].expo){
                swap(&p[j].expo, &p[j+1].expo);
                swap(&p[j].coef, &p[j+1].coef);
                flag++;
            }
        }
        if(flag == 0)
            break;
    }
}

void superscript(int x){
    SetConsoleOutputCP(CP_UTF8);
    if(x<0){
         x=-x;
         printf("⁻");
    }
    if(x==0)
        printf("⁰");
    if(x==1)
        printf("¹");
    if(x==2)
        printf("²");
    if(x==3)
        printf("³");
    if(x==4)
        printf("⁴");
    if(x==5)
        printf("⁵");
    if(x==6)
        printf("⁶");
    if(x==7)
        printf("⁷");
    if(x==8)
        printf("⁸");
    if(x==9)
        printf("⁹");
    if(x>9){
        breakNumber(x);
    }

}

void breakNumber(int n){
    int val, temp = 0, zero = 0;
   while(n>0) {
		val = n%10;
		if(val==0)
            zero++;
		n /= 10;
		temp = temp*10 + val;
	}
	while(temp>0) {
		val = temp%10;
		temp /= 10;
		superscript(val);

	}
	while(zero){
        superscript(0);
        zero--;
	}
}


void printPoly(poly *p, int size){
    if(size == 0){
        printf("ZERO!!!\n");
        return ;
    }
    for(int i = 0; i < size; i++){
        if(p[i].coef > 0){
            if(i!=0 && i<=size-1)
                printf(" + ");
            if(p[i].expo == 0){
                printf("%d", p[i].coef);
            }
            if(p[i].coef == 1 && p[i].expo == 1){
                printf("x");
            }
            if(p[i].expo != 0 && p[i].coef != 1){
                printf("%dx", p[i].coef);
            }


        }

        if(p[i].coef < 0){
            if(i<=size-1)
                printf(" - ");
            if(p[i].expo == 0){
                printf("%d", -p[i].coef);
            }
            if(p[i].coef == -1 && p[i].expo == 1){
                printf("x");
            }
            if(p[i].expo != 0 && p[i].coef != -1){
                printf("%dx", -p[i].coef);
            }
        }

        if(p[i].expo < 0 || p[i].expo > 1){
            superscript(p[i].expo);
        }
    }
    printf("\n");
}


poly* uniquePoly(poly *p, int *size){
    poly *temp = createPoly(temp, *size);
    poly *pol = createPoly(pol, *size);
    int counter = 0,k;
    for(int i = 0; i < *size; i++){
        k = i;
        temp[i].coef = p[i].coef;
        temp[i].expo = p[i].expo;
        for(int j = i+1; j < *size; j++){
            if(temp[i].expo == p[j].expo){
                temp[i].coef += p[j].coef;
                k = j;
            }
        }
        i = k;
    }
    sortPoly(temp, *size);
    k = 0;
    for(int i = 0; i < *size; i++){
        if(temp[i].coef != 0){
            pol[k] = temp[i];
            k++;
        }
        if(temp[i].coef == 0)
            counter++;
    }
    *size -= counter;
    p = realloc(pol, *size*sizeof(poly));
    return p;
}


poly* addPoly(poly *a, poly *b, poly *c, int sizeA, int sizeB, int *sizeC){
    int i,j,k = 0;
    for(i = 0; i < sizeA; i++,k++){
        c[k] = a[i];
    }
    for(j = 0; j < sizeB; j++,k++){
        c[k] = b[j];
    }
    sortPoly(c, *sizeC);
    c = uniquePoly(c, sizeC);
    return c;
}



int main(void){
    poly *a, *b, *sum;
    int sizeA, sizeB, sizeC;


    printf("Enter the size of 1st polynomials: ");
    scanf("%d", &sizeA);
    printf("\nEnter the size of 2nd polynomials: ");
    scanf("%d", &sizeB);

    /** POLY - A */
    printf("\nPolynomial-1\n");
    a = createPoly(a, sizeA);
    insertElements(a, sizeA);
    sortPoly(a, sizeA);
    a = uniquePoly(a, &sizeA);
    printf("1st polynomial: ");
    printPoly(a, sizeA);


    /** POLY - B */
    printf("\nPolynomial-2\n");
    b = createPoly(b, sizeB);
    insertElements(b, sizeB);
    sortPoly(b, sizeB);
    b = uniquePoly(b, &sizeB);
    printf("2nd polynomial: ");
    printPoly(b, sizeB);

    /** POLY - SUM */
    sizeC = sizeA+sizeB;
    sum = createPoly(sum, sizeC);
    sum = addPoly(a,b,sum,sizeA,sizeB, &sizeC);

    printf("\n\nThe 1st polynomial: \n");
    printPoly(a, sizeA);
    printf("The 2nd polynomial: \n");
    printPoly(b, sizeB);
    printf("Polynomial after addition: \n");
    printPoly(sum, sizeC);

    free(a);
    free(b);
    free(sum);
    return 0;
}


/**

Enter the size of 1st polynomials: 4
Enter 4 terms of the polynomial expression
Element[1]:
coef: 3
expo: 4
Element[2]:
coef: 7
expo: 3
Element[3]:
coef: 5
expo: 1
Element[4]:
coef: 8
expo: 0


Enter the size of 2nd polynomials: 5
Enter 5 terms of the polynomial expression
Element[1]:
coef: 7
expo: 5
Element[2]:
coef: 6
expo: 4
Element[3]:
coef: 8
expo: 2
Element[4]:
coef: 9
expo: 1
Element[5]:
coef: 2
expo: 0

The 1st polynomial:
3x⁴ + 7x³ + 5x + 8
The 2nd polynomial:
7x⁵ + 6x⁴ + 8x² + 9x + 2
Polynomial after addition:
7x⁵ + 9x⁴ + 7x³ + 8x² + 14x + 10

*/

/*
Enter the size of 1st polynomials: 5

Enter the size of 2nd polynomials: 4

Polynomial-1
Enter 5 terms of the polynomial expression
Element[1]:
coef: 3
expo: 5
Element[2]:
coef: 1
expo: 4
Element[3]:
coef: 2
expo: 3
Element[4]:
coef: -2
expo: 1
Element[5]:
coef: 5
expo: 0

1st polynomial: 3x⁵ + x⁴ + 2x³ - 2x + 5   

Polynomial-2
Enter 4 terms of the polynomial expression
Element[1]:
coef: 2
expo: 5
Element[2]:
coef: 3
expo: 3
Element[3]:
coef: 7
expo: 1
Element[4]:
coef: 2
expo: 0

2nd polynomial: 2x⁵ + 3x³ + 7x + 2


The 1st polynomial:
3x⁵ + x⁴ + 2x³ - 2x + 5
The 2nd polynomial: 
2x⁵ + 3x³ + 7x + 2
Polynomial after addition:
5x⁵ + x⁴ + 5x³ + 5x + 7

*/