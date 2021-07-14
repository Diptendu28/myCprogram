/*queue using link list*/
#include <stdio.h>
#include <stdlib.h>

//Linked List data type
typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void Enqueue(int val)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    printf("\n Enter the value you want to insert : ");
	scanf("%d",&val);
    if (ptr == NULL)
    {
        printf("\nNode cannot be created\n");
//        exit(0);
		return;
    }
    ptr->data = val;
    if (front == NULL && rear == NULL)
    {
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = rear->next;
        rear->next = NULL;
    }
}

void Dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue empty !!!\n");
//        exit(0);
		return;
    }
    Node *ptr = front;
    front = front->next;
    free(ptr);
    printf("\nDequeue successful\n");
}

void Peek()
{
    if (front == NULL)
    {
        printf("\nQueue empty !!!\n");
//        exit(0);
		return;
    }
	printf("\nFront most val is : %d", front->data);
}

void Display()
{
    Node *f = front;
    Node *r = rear;
    if(front==NULL&&rear==NULL){
    	printf("\nQueue empty !!!\n");
    	return;
	}
    do
    {
        printf("\nElement : %d", f->data);
        f = f->next;
    } while (f != r);
    printf("\nElement : %d", f->data);
}

int main()
{
	int ch,val;
	do
	{
		printf("\n\n ---Menu for Queue Operations---\n");
		printf("\n Press 1 for Enqueue\n Press 2 for Dequeue\n Press 3 to display the queue\n Press 4 to display the peek\n Press 0 to exit");
		printf("\n Enter your option : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	Enqueue(val);
					break;
			case 2: Dequeue();
					break;
			case 3: Display();
					break;
			case 4:	Peek();
					break;
			case 0: printf("\n Exit...\n");
					break;
			default: printf("\n Wrong choice.... please try again...\n");
		}
	}
	while(ch!=0);
	return 0;
}
