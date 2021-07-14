/*checking whether it is palindrome or not*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10
char stack[Max];
int top=-1;
struct Node
{
    char data;
    struct Node *link;
};

struct Node *head=NULL;
void push(int x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
void Create()
{
    int n,i;
    struct Node *ptr, *Cptr;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n == 0)
        return;
    ptr = (struct Node *)calloc(1,sizeof(struct Node));
    printf("Enter data: ");
    scanf("%s",&ptr->data);
    push(ptr->data);
    head = ptr;
	for(i=2;i<=n;i++)
    {
        Cptr=(struct Node *)calloc(1,sizeof(struct Node));
        printf("Enter data: ");
        scanf("%s",&Cptr->data);
        push(Cptr->data);
        ptr->link = Cptr;
        ptr = Cptr;
    }
    ptr->link=NULL;
}
void Display()
{
    struct Node * ptr;
    ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%c->",ptr->data);
        ptr = ptr->link;
    }
    printf("%c",ptr->data);
    printf("\n\n");
}
int palindrome()
{
    struct Node *ptr = head;
	while(ptr!=NULL)
    {
        if(ptr->data!=pop())
            return 0;
        ptr = ptr->link;
    }
    return 1;
}
int main()
{
    Create();
    Display();
	if(palindrome())
        printf("This is a palindrome\n");
    else
        printf("This is not a palindrome\n");
	return 0;
}
