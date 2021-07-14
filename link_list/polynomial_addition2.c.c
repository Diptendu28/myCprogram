/*polynomial addition*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList
{
    int coeff;
    int expi;
    struct LinkedList *next;
}Poly;

Poly *CreatePoly(Poly *head)
{
    Poly *p,*q,*node;
    int coeff,pow,opt;
    int flag;
    do
    {
        flag=1;
		node=(Poly *)malloc(sizeof(Poly));
		printf("\nCoeffecient : ");
        scanf("%d", &coeff);
        printf("\nExponent : ");
        scanf("%d", &pow);
        node->coeff = coeff;
        node->expi = pow;
//        printf("%d",node->expi);
		if(head!=NULL)
		{
			p=head;
			while(p!=NULL)
			{
				if(node->expi==p->expi)
				{
					flag=0;
					printf("invalid exponent input\n");
					break;
				}
				p=p->next;
			}
		}
		if(flag)
		{
			if(head==NULL)
    		{
//        		printf("x");
				head=node;
        		node->next=NULL;
//        		printf("%d",head->expi);
//        		DisplayPoly(head);
    		}
			else if((node->expi)<(head->expi))
			{	
//				printf("z");
				p=head;
				q=NULL;
				while(p!=NULL)
				{
					q=p;
					p=p->next;
					if(p==NULL)
					{
						q->next=node;
						node->next=NULL;
//						printf("e");
						break;	
					}
					if((p->expi)<(node->expi))
					{
						q->next=node;
						node->next=p;
						break;
					}
				}
			}
        	else 
			{
//	        	printf("y");
				node->next=head;
        		head=node;
    		}
		}
		printf("\nWant to add new term, press 1 else 0 : ");
        scanf("%d",&opt);
    }while (opt);
    return head;
}
Poly *AddPoly(Poly *res, Poly *f, Poly *s)
{
    Poly *node = (Poly *)malloc(sizeof(Poly));
    node->next = NULL;
    res = node;
    while (f && s)
    {
        if (f->expi > s->expi)
        {
            node->coeff = f->coeff;
            node->expi = f->expi;
            f = f->next;
        }
        else if (f->expi < s->expi)
        {
            node->coeff = s->coeff;
            node->expi = s->expi;
            s = s->next;
        }
        else
        {
            node->coeff = f->coeff + s->coeff;
            node->expi = f->expi;
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
            node->expi = f->expi;
            f = f->next;
        }
        else
        {
            node->coeff = s->coeff;
            node->expi = s->expi;
            s = s->next;
        }
    }
    return res;
}

void DisplayPoly(Poly *ptr)
{
    if(ptr==NULL)
	{
		printf("empty polynomial\n");
		return;
	}
	printf("\nPolynomial expression is: ");
    while (ptr != NULL)
    {
        if(ptr->coeff==0)
        {
        	while(ptr->coeff==0)
        		ptr=ptr->next;
        	if(ptr->coeff>0)
				printf(" + ");
        	continue;
		}
		if(ptr->expi==0)
        	printf("%d ",ptr->coeff);
        else if(ptr->expi==1)
        	printf("%dX",ptr->coeff);
        else
			printf("%dX^%d ",ptr->coeff,ptr->expi);
        ptr = ptr->next;
        if(ptr==NULL)
        	break;
        if(ptr->coeff>0)
            printf(" + ");
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
    DisplayPoly(first);
    printf("\nSecond Polynomial--------------------------------------------\n");
    second = CreatePoly(second);
    DisplayPoly(second);
    printf("\nResultant Polynomial-----------------------------------------\n");
    DisplayPoly(first);
    DisplayPoly(second);
    result = AddPoly(result, first, second);
    DisplayPoly(result);
    return 0;
}

