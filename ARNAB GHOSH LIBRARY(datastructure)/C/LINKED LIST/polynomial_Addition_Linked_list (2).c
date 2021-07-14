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

poly* addpoly(poly *h1, poly *h2){
    poly *ptr1, *ptr2, *h3;
    h3 = NULL;
    ptr1 = h1;
    ptr2 = h2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr2->exp > ptr1->exp){
            h3 = addNode(ptr2->coef, ptr2->exp, h3);
            ptr2 = ptr2->next;
        }
        else if(ptr2->exp < ptr1->exp){
            h3 = addNode(ptr1->coef, ptr1->exp, h3);
            ptr1 = ptr1->next;
        }
        else{
            h3 = addNode(ptr1->coef + ptr2->coef, ptr1->exp, h3);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL){
        h3 = addNode(ptr1->coef, ptr1->exp, h3);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        h3 = addNode(ptr2->coef, ptr2->exp, h3);
        ptr2 = ptr2->next;
    }
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
    phead = addpoly(p1, p2);
    printf("The final poly after addition:\n");
    display(phead);
    printf("\n");
    system("pause");
    return 0;
}

/**


OUTPUT 1
--------


Enter elements in the 1st poly:
coef: 2
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 3
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 1
exp: 4

Enter 1 to add or Enter 0 to stop: 1
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 1
coef: -2
exp: 1

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
3x^5 + 1x^4 + 2x^3 + -2x^1 + 5x^0

Enter elements in the 2nd poly:
coef: 7
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: 3
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 2
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 2
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
2x^5 + 3x^3 + 7x^1 + 2x^0

The 1st poly:
3x^5 + 1x^4 + 2x^3 + -2x^1 + 5x^0

The 2nd poly:
2x^5 + 3x^3 + 7x^1 + 2x^0

The final poly after addition:
5x^5 + 1x^4 + 5x^3 + 5x^1 + 7x^0

Press any key to continue . . .





OUTPUT 2
--------


Enter elements in the 1st poly:
coef: 2
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 3
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 1
exp: 4

Enter 1 to add or Enter 0 to stop: 1
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 1
coef: -2
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
3x^5 + 1x^4 + 2x^3 + 3x^0


Enter elements in the 2nd poly:
coef: 7
exp: 6

Enter 1 to add or Enter 0 to stop: 2
coef: 2
exp: 2

Enter 1 to add or Enter 0 to stop: 1
coef: 4
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 3
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 10
exp: -2

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
7x^6 + 4x^5 + 3x^3 + 2x^2 + 10x^-2

The 1st poly:
3x^5 + 1x^4 + 2x^3 + 3x^0

The 2nd poly:
7x^6 + 4x^5 + 3x^3 + 2x^2 + 10x^-2

The final poly after addition:
7x^6 + 7x^5 + 1x^4 + 5x^3 + 2x^2 + 3x^0 + 10x^-2






OUTPUT 3
--------


Enter elements in the 1st poly:
coef: 8
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: 4
exp: 2

Enter 1 to add or Enter 0 to stop: 1
coef: -12
exp: 0

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
4x^2 + 8x^1 + -12x^0


Enter elements in the 2nd poly:
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 1
coef: 3
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: -13
exp: 1

Enter 1 to add or Enter 0 to stop: 0
You have inserted:
3x^3 + -13x^1 + 5x^0

The 1st poly:
4x^2 + 8x^1 + -12x^0

The 2nd poly:
3x^3 + -13x^1 + 5x^0

The final poly after addition:
3x^3 + 4x^2 + -5x^1 + -7x^0


*/
