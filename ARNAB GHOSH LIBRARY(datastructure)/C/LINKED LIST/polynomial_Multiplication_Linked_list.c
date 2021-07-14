/*polynomial_multiplication*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node *next;
} poly;



poly *p1head = NULL;
poly *p2head = NULL;
poly *phead = NULL;


poly* addNode(int coef, int exp, poly *head){ // Code of sorted order insertion
    poly *temp,*ptr, *cptr;

    temp = (poly*)malloc(sizeof(poly));
    temp->next = NULL;
    temp->coef = coef;
    temp->exp = exp;

    ptr = head;

    if(ptr == NULL || exp > ptr->exp){ // NULL and insert before
        temp->next = head;
        head = temp;
        return head;
    }

    while(ptr != NULL){ // total insertion completed in O(n)
        if(exp == ptr->exp){ // adding coefs
            ptr->coef+=coef;
            return head;
            free(temp);
        }
        else if(exp < ptr->exp && (ptr->next == NULL || exp > ptr->next->exp)){ // insert after and NULL
            temp->next = ptr->next;
            ptr->next = temp;
            return head;
        }
        ptr = ptr->next;
    }
}

poly* multiplypoly(poly *h1, poly *h2){
    poly *ptr1, *ptr2, *h3;
    h3 = NULL;
    for(ptr1 = h1; ptr1 != NULL; ptr1 = ptr1->next)
        for(ptr2 = h2; ptr2 != NULL; ptr2 = ptr2->next)
            h3 = addNode(ptr1->coef * ptr2->coef,  ptr1->exp + ptr2->exp, h3);
    return h3;
}


void display(poly *ptr){
    while (ptr != NULL){
        printf("%dx^%d ", ptr->coef, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL)
            printf("+ ");
    }
    printf("\n\n");
}



int main(void){
    poly *p1, *p2;
    int flag = 1, coef, exp;
    printf("Enter elements in the 1st poly: \n");
    while(flag){
        printf("coef: ");
        scanf("%d", &coef);
        printf("exp: ");
        scanf("%d", &exp);
        p1 = addNode(coef, exp, p1head);
        p1head = p1;
        printf("\nEnter 1 to add or Enter 0 to stop: ");
        scanf("%d",&flag);
        if(flag)
            continue;
        break;
    }
    printf("You have inserted:\n");
    display(p1);
    flag = 1;
    printf("\nEnter elements in the 2nd poly: \n");
    while(flag){
        printf("coef: ");
        scanf("%d", &coef);
        printf("exp: ");
        scanf("%d", &exp);
        p2 = addNode(coef, exp, p2head);
        p2head = p2;
        printf("\nEnter 1 to add or Enter 0 to stop: ");
        scanf("%d",&flag);
        if(flag)
            continue;
        break;
    }
    printf("You have inserted:\n");
    display(p2);
    printf("The 1st poly:\n");
    display(p1);
    printf("The 2nd poly:\n");
    display(p2);
    phead = multiplypoly(p1, p2);
    printf("The final poly after addition:\n");
    display(phead);
    printf("\n");
    system("pause");
    return 0;
}

/**

Output 1
---------

Enter elements in the 1st poly:
coef: 4
exp: 2

Enter 1 to add or Enter 0 to stop: 1
coef: 1
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
4x^2 + 1x^1 + 5x^0


Enter elements in the 2nd poly:
coef: 3
exp: 6

Enter 1 to add or Enter 0 to stop: 1
coef: 2
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
3x^6 + 2x^5 + 5x^0

The 1st poly:
4x^2 + 1x^1 + 5x^0

The 2nd poly:
3x^6 + 2x^5 + 5x^0

The final poly after addition:
12x^8 + 11x^7 + 17x^6 + 10x^5 + 20x^2 + 5x^1 + 25x^0


Press any key to continue . . .


Output 2
---------

Enter elements in the 1st poly:
coef: 4
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: -3
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
4x^1 + -3x^0


Enter elements in the 2nd poly:
coef: 5
exp: 2

Enter 1 to add or Enter 0 to stop: 1
coef: -2
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: -1
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
5x^2 + -2x^1 + -1x^0

The 1st poly:
4x^1 + -3x^0

The 2nd poly:
5x^2 + -2x^1 + -1x^0

The final poly after addition:
20x^3 + -23x^2 + 2x^1 + 3x^0


Press any key to continue . . .



*/
