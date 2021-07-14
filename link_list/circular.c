/*circular*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void insert_begin(struct node **tail)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter item:\n");
    scanf("%d",&ptr->data);
    if(*tail==NULL)
    {
        ptr->link=ptr;
        *tail=ptr;
        return;
    }
    ptr->link=(*tail)->link;
    (*tail)->link=ptr;


}
void insert_end(  struct node **tail)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter item:\n");
    scanf("%d",&ptr->data);
    if(*tail==NULL)
    {
        ptr->link=ptr;
        *tail=ptr;
//        free(ptr);
        return;
    }
    
    ptr->link=(*tail)->link;
    (*tail)->link=ptr;
    *tail=ptr;
}
void insert_after(struct node **tail)//problem
{
    int item;
    printf("enter the element after:");
    scanf("%d",&item);
    struct node *ptr,*cptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter item:\n");
    scanf("%d",&ptr->data);
//    cptr=(*tail)->link;
    if(*tail==NULL)
    	return;
    cptr=(*tail)->link;	
//    while(cptr!=*tail)
	do
    {
        if(cptr->data==item)
        {
			ptr->link=cptr->link;
            cptr->link=ptr;
            if(cptr==*tail)
            	*tail=ptr;
            return;
        }
        cptr=cptr->link;
    }while(cptr!=(*tail)->link);
//    ptr->link=cptr->link;
//    cptr->link=ptr;
//    *tail=ptr;
	printf("\nitem not found!!\n");

    
}
void delete_node(struct node **tail)
{
    struct node *ptr,*cptr;int item;
    printf("enter the data to be deleted:");
    scanf("%d",&item);
    if(*tail==NULL)
    	return;
    if((*tail)->link==*tail&&(*tail)->data==item)
    {
        *tail=NULL;
        return;
    }
    ptr=(*tail);
    while(ptr->link!=*tail)
    {
        if(ptr->link->data==item)
        {
            cptr=ptr->link;
            ptr->link=ptr->link->link;
            free(cptr);
            return;
        }
        ptr=ptr->link;
	}
    if((*tail)->data==item)
    {
        cptr=*tail;
        ptr->link=(*tail)->link;
        *tail=ptr;
        free(cptr);
        return;
    }
    printf("element not present\n");


}
//void display(struct node *tail)
//{
//    struct node *ptr;
//    if(tail==NULL)
//    {
//        printf("nothing to display\n");
//        return;
//    }
//    while(ptr!=tail)
//    {
//        printf("%u->%d->%u , ",ptr,ptr->data,ptr->link);
//        ptr=ptr->link;
//    }
//    printf("%u->%d->%u\n",tail,tail->data,tail->link);
//}
void display(struct node *tail)
{
    struct node *ptr;
    if(tail==NULL)
    {
        printf("nothing to display\n");
        return;
    }
    ptr=tail->link;
	do
    {
	    printf("%u->%d->%u",ptr,ptr->data,ptr->link);
	    if(ptr->link!=tail->link)
	    	printf(",");
    	ptr=ptr->link;
    }while(ptr!=tail->link);
}

//int main()
//{
//    struct node *tail;
//    int ch;
//    tail=NULL;
//    do
//    {
//        printf("enter: \n1 for insert at begining\n2 for insert at end\n3 for display\n4 to exit\n5 for insert after\n6 to delete node\n");
//        scanf("%d",&ch);
//        switch(ch)
//        {
//            case 1:
//            insert_begin(&tail);
//            break;
//            case 2:
//            insert_end(&tail);
//            break;
//            case 3:
//            display(tail);
//            break;
//            case 4:
//            exit(1);
//            case 5:
//            insert_after(&tail);
//            break;
//            case 6:
//            delete_node(&tail);
//            break;
//            default:
//            printf("wrong choice");
//        }
//    } while (1);
//    return 0;
//}
int main()
{
    struct node *tail;
    int ch;
    tail=NULL;
    do
    {
        printf("\n1 for insert at begining\n2 for insert at end\n3 for display\n4 to exit\n5 for insert after\n6 to delete node\n");
        printf("\nEnter : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert_begin(&tail);
                    break;
            case 2:	insert_end(&tail);
            		break;
            case 3:	display(tail);
            		break;
            case 4:	exit(1);
            case 5:	insert_after(&tail);
            		break;
            case 6:	delete_node(&tail);
            		break;
            default:printf("Wrong choice\n");
        }
    }while (1);
    return 0;
}
