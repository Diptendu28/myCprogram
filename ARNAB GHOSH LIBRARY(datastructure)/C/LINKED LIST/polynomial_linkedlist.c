#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int coeff;
    int exp;
    struct LinkedList *next;
} Poly;

Poly* CreatePoly(Poly *ptr)
{
    Poly *node = (Poly *)malloc(sizeof(Poly));
    ptr = node;
    int coeff, pow, opt;
    do
    {
        printf("\nCoeffecient : ");
        scanf("%d", &coeff);
        printf("\nExponent : ");
        scanf("%d", &pow);
        node->coeff = coeff;
        node->exp = pow;
        node->next = NULL;
        printf("\nWant to add new term, press 1 else 0 : ");
        scanf("%d", &opt);
        if (opt)
        {
            node->next = (Poly *)malloc(sizeof(Poly));
            node = node->next;
            node->next = NULL;
        }
    } while (opt);
    return ptr;
}

Poly* AddPoly(Poly *res, Poly *f, Poly *s)
{
    Poly *node = (Poly *)malloc(sizeof(Poly));
    node->next = NULL;
    res = node;
    while (f && s)
    {
        if (f->exp > s->exp)
        {
            node->coeff = f->coeff;
            node->exp = f->exp;
            f = f->next;
        }
        else if (f->exp < s->exp)
        {
            node->coeff = s->coeff;
            node->exp = s->exp;
            s = s->next;
        }
        else
        {
            node->coeff = f->coeff + s->coeff;
            node->exp = f->exp;
            f = f->next;
            s = s->next;
        }
        if (f && s)
        {
            node->next = (Poly *)malloc(sizeof(Poly));
            node = node->next;
            node->next = NULL;
        }
    }
    while (f || s)
    {
        node->next = (Poly *)malloc(sizeof(Poly));
        node = node->next;
        node->next = NULL;
        if (f)
        {
            node->coeff = f->coeff;
            node->exp = f->exp;
            f = f->next;
        }
        else
        {
            node->coeff = s->coeff;
            node->exp = s->exp;
            s = s->next;
        }
    }
    return res;
}

void DisplayPoly(Poly *ptr)
{
    printf("\nThe Polynomial expression is : ");
    while (ptr != NULL)
    {
        printf("%dx^%d ", ptr->coeff, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL)
            printf("+ ");
    }
}

int main()
{
    Poly *first = NULL;
    Poly *second = NULL;
    Poly *result = NULL;
    printf("\n--------------------Polynomial Addition----------------------\n");
    printf("\nFirst Polynomial---------------------------------------------\n");
    first = CreatePoly(first);
    printf("\nSecond Polynomial--------------------------------------------\n");
    second = CreatePoly(second);
    printf("\nResultant Polynomial-----------------------------------------\n");
    DisplayPoly(first);
    DisplayPoly(second);
    result = AddPoly(result, first, second);
    DisplayPoly(result);
    printf("\n");
    system("pause");
    return 0;
}
