/*spliting of a circular linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};
int ct=0;
void insertend(struct node **tail)
{
	ct++;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("enter item");
	scanf("%d",&ptr->data);
	if(*tail==NULL)
	{
		ptr->next=ptr;
		*tail=ptr;
		return;
	}
	ptr->next=(*tail)->next;
	(*tail)->next=ptr;
	*tail=ptr;
}
void sp(struct node **tail1,struct node **tail2,struct node **tail)
{
	int a=1;
	struct node *ptr,*temp;
	*tail2=*tail;
	ptr=(*tail);
	while(a<=ct/2)
	{
		ptr=ptr->next;
		a++;
	}
	temp=(*tail)->next;
	(*tail2)->next=ptr->next;
	ptr->next=temp;
	(*tail1)=ptr;
}
void display(struct node *tail)
{
    struct node *ptr=tail->next;
    if(tail==NULL)
    {
        printf("nothing to display\n");
        return;
    }
    while(ptr!=tail)
    {
        printf("%u->%d->%u , ",ptr,ptr->data,ptr->next);
        ptr=ptr->next;
    }
    printf("%u->%d->%u\n",tail,tail->data,tail->next);
}

int main()
{
    int ch;struct node *tail=NULL,*tail1=NULL,*tail2=NULL;
    while(1)
    {
        printf("\nenter 1 to enter data and 0 to exit:");
        scanf("%d",&ch);
        if(ch==1)
        	insertend(&tail);
        else if(ch==0)
        	break;
        else
        {
            printf("wrong choice");
        }
    }
    if(ct%2==1)
    	printf("no splitting can be done\n");
    else
    {
        printf("created list:\n");
        display(tail);
        sp(&tail1,&tail2,&tail);
        printf("splitted list:\n");
        display(tail1);
        display(tail2);
    }
    return 0;
}
