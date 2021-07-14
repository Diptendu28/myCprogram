#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
int count;


void display(node *ptr)
{
    if(ptr == NULL)
	{
        printf("Nothing to Print\n");
        return ;
    }
    while(ptr->next != NULL)
	{
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}


node* addNode(int value)
{
    node *temp,*ptr;

    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = value;

     if(head == NULL)
	 {
        head = temp;
     }

    else
	{
        ptr = (node*)malloc(sizeof(node));
        ptr->next = NULL;
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}


node* swap(node* ptr1, node* ptr2)
{
    node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}



void bubbleSort()
{
    int i,j;
	node **h;
    for( i = 0; i<count-1;i++)
	{
        h=&head;
        for( j=0; j < count-i-1; j++)
		{
            node *p1 = *h;
            node *p2 = p1->next;
            if(p1->data > p2->data)
                *h = swap(p1, p2);
            h = &(*h)->next;
        }
    }
}



int main(void)
{
    int t;
    node* ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    count = t;
    printf("Insert %d values:--\n", t);
    while(t--){
        int val;
        scanf("%d", &val);
        ptr = addNode(val);
    }
    printf("The original linked list are:\n");
    display(head);
    bubbleSort();
    printf("The updated linked list are:\n");
    display(head);
//    system("pause");
    return 0;
}



/**


void bubbleSort(){
    node **h;
    for(int i = 0; i < count - 1; i++){
        h = &head;
        for(int j = 0; j < count - i - 1; j++){
            node *p1 = *h;
            node *p2 = p1->next;
            if(p1->data > p2->data)
                *h = swap(p1, p2);
            h = &(*h)->next;
        }
    }
}


*/
