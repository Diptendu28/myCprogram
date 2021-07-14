/*polynomial addition(using structure)*/
#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
    int coef;
    int exp;
}p;
void sort(p *a,int n)
{
    int i,j,temp,flag=0;
    for(i=0;i<n-1;i++)
    {   flag =0;
       for(j=0;j<n-i-1;j++)
        if(a[j].exp<a[j+1].exp)
        {
            swap(&a[j].exp,&a[j+1].exp);
            swap(&a[j].coef,&a[j+1].coef);
            flag=1;
        }
        if(flag==0)
        break; 
    }
//    printf("%d ",i);
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void input(p *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter exp:");
        scanf("%d",&a[i].exp);
        printf("\nenter coef:");
        scanf("%d",&a[i].coef);
    }
}
void display(p *c,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        printf("%dx^%d + ",c[i].coef,c[i].exp);
    }
    printf("%dx^%d",c[i].coef,c[i].exp);
}
int main()
{
    int n1,n2,n3,i=0,j=0,k=0;
    p *a,*b,*c;
    printf("enter the no. of terms of 1st polynomial\n");
    scanf("%d",&n1);
    a=(p*)malloc(n1*sizeof(p));
    input(a,n1);
    sort(a,n1);
    printf("enter the no. of terms of 2nd polynomial\n");
    scanf("%d",&n2);
    b=(p*)malloc(n2*sizeof(p));
    input(b,n2);
    sort(b,n2);
    printf("\n1st polynomial is:");
    display(a,n1);
    printf("\n2nd polynomial is:");
    display(b,n2);
    printf("\nsum polynomial:");
    n3=n1>n2?n1:n2;
    c=(p*)malloc(n1+n2*sizeof(p));
    while(i<n1&&j<n2)
    {
        if(a[i].exp==b[j].exp)
        {
            c[k].coef=a[i].coef+b[j++].coef;
            c[k++].exp=a[i++].exp;
        }
        else if(a[i].exp>b[j].exp)
        {
            c[k].coef=a[i].coef;
            c[k++].exp=a[i++].exp;
        }
        else
        {
            c[k].coef=b[j].coef;
            c[k++].exp=b[j++].exp;
        }
    }
    while(i<n1||j<n2)
    {
        if(i<n1)
        {
            c[k].coef=a[i].coef;
            c[k++].exp=a[i++].exp;
        }
        else
        {
           	c[k].coef=b[j].coef;
            c[k++].exp=b[j++].exp; 
        }
    }
    display(c,k);
    return 0;
}
