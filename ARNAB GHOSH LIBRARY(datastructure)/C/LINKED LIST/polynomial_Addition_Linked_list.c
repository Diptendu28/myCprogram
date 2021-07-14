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


poly* addNode(int coef, int exp, poly *head){
    poly *temp,*ptr;
    temp = (poly*)malloc(sizeof(poly));
    temp->next = NULL;
    temp->coef = coef;
    temp->exp = exp;

     if(head == NULL)
        head = temp;
    else{
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}



void display(poly *ptr){
    printf("\nThe Polynomial is given:\n");
    while (ptr != NULL){
        printf("%dx^%d ", ptr->coef, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL)
            printf("+ ");
    }
    printf("\n");
}

void swap(poly *a, poly *b){
    int temp = a->exp;
    a->exp = b->exp;
    b->exp = temp;
}

void bubbleSort(poly *head){
    int flag;
    poly *ptr = head;
    poly *cptr = NULL;

    if (head == NULL)
        return;
    do{
        flag = 0;
        ptr = head;
        while (ptr->next != cptr){
            if (ptr->exp < ptr->next->exp){
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        cptr = ptr;
    } while (flag);
}


poly* addpoly(poly *ptr1, poly *ptr2){
    while (ptr1->next && ptr2->next){
        if(ptr1->exp > ptr2->exp){
            phead = addNode(ptr1->coef, ptr1->exp, phead);
            ptr1 = ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp){
            phead = addNode(ptr2->coef, ptr2->exp, phead);
            ptr2 = ptr2->next;
        }
        else{
            phead = addNode(ptr1->coef+ptr2->coef, ptr1->exp, phead);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1->next || ptr2->next){
        if (ptr1->next){
            phead = addNode(ptr1->coef, ptr1->exp, phead);
            ptr1 = ptr1->next;
        }
        if (ptr2->next){
            phead = addNode(ptr2->coef, ptr2->exp, phead);
            ptr2 = ptr2->next;
        }
    }
    return phead;
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
    flag = 1;
    printf("Enter elements in the 2nd poly: \n");
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
    bubbleSort(p1);
    bubbleSort(p2);
    display(p1);
    display(p2);
    phead = addpoly(p1, p2);
    display(phead);
    system("pause");
    return 0;
}


/**

Enter elements in the 1st poly:
coef: 5
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 2
exp: 2

Enter 1 to add or Enter 0 to stop: 1
coef: 7
exp: 1

Enter 1 to add or Enter 0 to stop: 1
coef: 5
exp: 0

Enter 1 to add or Enter 0 to stop: 0
Enter elements in the 2nd poly:
coef: 7
exp: 5

Enter 1 to add or Enter 0 to stop: 1
coef: 4
exp: 4

Enter 1 to add or Enter 0 to stop: 1
coef: 2
exp: 3

Enter 1 to add or Enter 0 to stop: 1
coef: 7
exp: 0

Enter 1 to add or Enter 0 to stop: 0

The Polynomial is given:
5x^3 + 2x^2 + 7x^1 + 5x^0

The Polynomial is given:
7x^5 + 4x^4 + 2x^3 + 7x^0

The Polynomial is given:
7x^5 + 4x^4 + 7x^3 + 2x^2 + 7x^1
Press any key to continue . . .


*/
