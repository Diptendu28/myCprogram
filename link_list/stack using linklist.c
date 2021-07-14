/*---------------------------------------------------
For linked list we will always push and pop from the beginning
to point head of the linked list we used "top"
----------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;
void push()
{
    int value;
    printf("\nEnter the value to be pushed : ");
    scanf("%d",&value);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(top==NULL)
        printf("\nUNDERFLOW!!!");
    else
	{
    	struct node *temp;
    	temp=top;
    	printf("Deleted item is : %d",top->data);
    	top=temp->next;
    	temp->next=NULL;
    	free(temp);
    }
}
void display()
{
    if(top==NULL)
      printf("\nNothing to display.. stack is empty.");
    else
	{
        struct node *temp;
        temp=top;
        printf("\nPrinting the values...\n");
        printf("Top--->");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
	int decision=1,operation;
	while(decision==1)
  	{
  		printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 to display stack\nEnter 0 to quit\n");
  		printf("\nEnter the operation : ");
  		scanf("%d",&operation);
  		switch(operation)
		{
  			case 1:	push();
    				break;
  			case 2: pop();
      				break;
  			case 3: display();
      				break;
      		case 0:	decision=0;
    				break;
    		default:printf("\nWrong choice... please try again!!!\n");
    	}
	}
	return 0;
}
