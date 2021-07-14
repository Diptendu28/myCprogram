#include<stdio.h>
#include<math.h>
double binet(unsigned int n){
    static const double phi = (1 + sqrt(5))*0.5;
    double fib = (pow(phi,n) - pow(1-phi,n))/sqrt(5);
    return round(fib);
}
int main(void){
    unsigned int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        printf("%d\n", (int)binet(i));
    return 0;
}