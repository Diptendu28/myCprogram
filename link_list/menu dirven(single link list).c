/*menu driven program single link list */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void create()
{
    int n,i;
    struct node *ptr, *cptr;
    printf("enter no. of nodes:");
    scanf("%d", &n);
    if (n == 0)
        return;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &ptr->data);
    head = ptr;
    for (i = 2; i <= n; i++)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d", &cptr->data);
        ptr->link = cptr;
        ptr = cptr;
    }
    ptr->link=NULL;
}
void insert_begining()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&ptr->data);
    if(head==NULL)
    {
        head=ptr;
        ptr->link=NULL;
    }
    else
    {
        ptr->link=head;
        head=ptr;
    }
}
void insert_end()
{
    struct node *ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&ptr->data);
    cptr=head;
    while(cptr->link!=NULL)
    {
        cptr=cptr->link;
    }
    cptr->link=ptr;
    ptr->link=NULL;
    
}
void insert_before()
{
    struct node *ptr,*cptr,*tptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int element,f=0;
    printf("enter the element in the list you want to insert before:");
    scanf("%d",&element);
    printf("enter data:");
    scanf("%d",&ptr->data);
    cptr=head;
    while(cptr->link!=NULL)
    {
        if(cptr->data==element)
        {
            f=1;
            break;
        }
        else
        {
            tptr=cptr;
            cptr=cptr->link;
        }
    }
    if(f==1)
    {
        ptr->link=tptr->link;
        tptr->link=ptr;
    }
    else
    {
        printf("Element not found");
    }
}
void insert_after()
{
    struct node *ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int element,f=0;
    printf("enter the element in the list you want to insert after:");
    scanf("%d",&element);
    printf("enter data:");
    scanf("%d",&ptr->data);
    cptr=head;
    while(cptr!=NULL)
    {
        if(cptr->data==element)
        {
            f=1;
            break;
        }
        else
        {
            cptr=cptr->link;
        }
        
    }
    
    if(f==1)
    {
        ptr->link=cptr->link;
        cptr->link=ptr;
    }
    else
    {
        printf("Element not found");
    }
    
}
void insert_posi()
{
    struct node *ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int position,i=1;
    printf("enter the position:");
    scanf("%d",&position);
    printf("enter data:");
    scanf("%d",&ptr->data);
    cptr=head;
    while(cptr->link!=NULL)
    {
        if(i==position-1)
        break;
        else
        {
            cptr=cptr->link;
            i++;
        }
    }
    ptr->link=cptr->link;
    cptr->link=ptr;
    cptr=ptr;
}
void delete_begining()
{
    struct node *ptr;
	if(head==NULL)
    	printf("Nothing to delete");
    else
    {
        printf("\n %d is the deleted element ",head->data);
		ptr=head;
		head=head->link;
		free(ptr);
		
    }
    
}
void delete_end()
{
    struct node *cptr,*ptr;
    if(head==NULL)
    printf("Nothing to delete");
    else
    {
        ptr=cptr=head;
        while(cptr->link!=NULL)
        {
            ptr=cptr;
            cptr=cptr->link;
        }
        printf("deleted element is %d\n",cptr->data);  
        ptr->link=NULL;  
    }
}
void delete_node()
{
    int item;
    
    struct node *cptr,*ptr;
    if(head==NULL)
    	printf("Nothing to delete");
    else
    {
        printf("\nenter the node to be deleted:");
        scanf("%d",&item);
        ptr=cptr=head;
        while(cptr!=NULL)
        {
            if(cptr->data==item)
            	break;
            ptr=cptr;
            cptr=cptr->link;
        }
        printf("deleted element is %d\n",cptr->data); 
		if(cptr==head){
			head=head->link;
			free(cptr);
		} 
		else{
			ptr->link=cptr->link;
			free(cptr); 
		}
			 
    }
}
void reverse()
{
    struct node *ptr,*cptr,*tptr;
    ptr=head;
    cptr=ptr->link;
    while(cptr->link!=NULL)
    {
        tptr=cptr->link;
        cptr->link=ptr;
        ptr=cptr;
        cptr=tptr;
    }
    cptr->link=ptr;
    head->link=NULL;
    head=cptr;
}
void product()
{
	struct node *ptr=head;
	int p=1;
	while(ptr!=NULL)
	{
		p=p*(ptr->data);
		ptr=ptr->link;
	}
//	return p;
	printf("product of all the present nodes in link list is %d\n",p);
}
void display()
{
    struct node *ptr;
    if(head==NULL){
    	printf("empty link list!\n");
    	return;
	}
    	
    ptr = head;
    while (ptr->link != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}
int main()
{
    int ch;
    printf("Enter elements to create a linked list\n");
    create();
    do
    {
        printf("\nenter\n 1 to insert in begining\n 2 to insert at the end\n 3 to insert at a specific position\n 4 to delete the 1st node\n 5 to delete the last node\n 6 to delete a specific element\n 7 to reverse\n 8 to product\n 9 to display\n 10 to exit\n 11 to insert before\n 12 to insert after \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert_begining();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_posi();
            break;
            case 4:
            delete_begining();
            break;
            case 5:
            delete_end();
            break;
            case 6:
            delete_node();
            break;
            case 7:
            reverse();
            break;
            case 8:
            product();
            break;
            case 9:
            display();
            break;
            case 10:
            exit(1);
//            break;
			case 11:
            insert_before();
            break;
            case 12:
            insert_after();
            break;
			default:
            printf("wrong choice");
        }
    } while (1);
    return 0;
}
