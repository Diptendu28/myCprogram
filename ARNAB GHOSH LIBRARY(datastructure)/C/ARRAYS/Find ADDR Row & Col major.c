#include<stdio.h>
int main(){
    int BA,w;
    int i, ui, li;
    int j, uj, lj;
    int RM, CM;

    printf(" BA: ");
    scanf("%d",&BA);

    printf(" i: ");
    scanf("%d",&i);
    printf(" j: ");
    scanf("%d",&j);

    printf(" l1: ");
    scanf("%d",&li);
    printf(" u1: ");
    scanf("%d",&ui);

    printf(" l2: ");
    scanf("%d",&lj);
    printf(" u2: ");
    scanf("%d",&uj);

    printf(" w: ");
    scanf("%d",&w);

    RM = BA + ((i - li) * (uj - lj +1) + (j - lj)) * w;
    CM = BA + ((j - lj) * (ui - li +1) + (i - li)) * w;

    printf("The row major order address of a[%d][%d]: %d",i,j,RM);
    printf("\nThe column major address of a[%d][%d]: %d",i,j,CM);

    return 0;
}
