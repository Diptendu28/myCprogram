#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head1= NULL;
node *head2 = NULL;
node *head3 = NULL;

node* setNode(node *ptr){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void display(node *ptr){
    if(ptr == NULL){
        printf("\nNO COMMON VALUES!!!\n");
        return;
    }
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}


void swap(node *a, node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void Sort(node *head){
    int flag;
    node *ptr = head;
    node *cptr = NULL;

    if (head == NULL)
        return;
    do{
        flag = 0;
        ptr = head;
        while (ptr->next != cptr){
            if (ptr->data > ptr->next->data){
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        cptr = ptr;
    } while (flag);
}

node* addNode(int value, node* temp_head){
    node *temp, *ptr;
    temp = setNode(temp);
    temp->data = value;
     if(temp_head == NULL){
        temp_head = temp;
     }

    else{
        ptr = setNode(ptr);
        ptr = temp_head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return temp_head;
}


node* doIntersection(){
    node* ptr1 = head1;
    node* ptr2 = head2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data == ptr2->data){
            head3 = addNode(ptr1->data, head3);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->data < ptr2->data)
            ptr1 = ptr1->next;
        else if(ptr1->data > ptr2->data)
            ptr2 = ptr2->next;
    }
    return head3;
}

int main(void){
    node *LL1, *LL2, *LL3;
    int t;
    printf("Enter the Number of nodes(LL1): ");
    scanf("%d", &t);
    while(t--){
        int val;
        printf("Enter Data: ");
        scanf("%d", &val);
        LL1 = addNode(val, head1);
        head1 = LL1;
    }

    printf("Enter the Number of nodes(LL2): ");
    scanf("%d", &t);
    while(t--){
        int val;
        printf("Enter Data: ");
        scanf("%d", &val);
        LL2 = addNode(val, head2);
        head2 = LL2;
    }
    Sort(LL1);
    Sort(LL2);
    printf("Values of LL1\n");
    display(LL1);
    printf("Values of LL2\n");
    display(LL2);
    printf("The intersection of LL1 and LL2:\n");
    LL3 = doIntersection(head1, head2);
    display(LL3);
    system("pause");
    return 0;
}


/*#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* head3=NULL;


void create(struct node** head)
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
    *head = ptr;
    ptr->link=NULL;
    for (i = 2; i <= n; i++)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d", &cptr->data);
        ptr=*head;
        if(ptr->data>cptr->data)
        {
            cptr->link=*head;
            *head=cptr;
            continue;
        }
        
        while(ptr->link!=NULL)
        {
            if(ptr->link->data>=cptr->data)
            {
                cptr->link=ptr->link;
                ptr->link=cptr;
                break;
            }
            ptr=ptr->link;
        }
        if(ptr->link==NULL)
        {
            cptr->link=ptr->link;
            ptr->link=cptr;
        }
    }
}
void display(struct node **head)
{
    struct node *ptr;
    ptr = *head;
    printf("\n");
    while (ptr->link != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}
void intersection()
{
    struct node *ptr1,*ptr2,*ptr3,*cptr3;
    ptr1=head1;
    ptr2=head2;
    ptr3=head3;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->data==ptr2->data)
        {
            cptr3=(struct node*)malloc(sizeof(struct node));
            cptr3->data=ptr1->data;
            if(head3==NULL)
            head3=cptr3;
            else
            ptr3->link=cptr3;
            
            ptr3=cptr3;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->data<ptr2->data)
        ptr1=ptr1->link;
        else
        {
            ptr2=ptr2->link;
        }
        
    }
    cptr3->link=NULL;
}
int main()
{
    int ch;
    printf("Enter elements to create a linked list\n");
    create(&head1);
    display(&head1);
    create(&head2);
    display(&head2);
    intersection();
    display(&head3);
	return 0;
}*/
