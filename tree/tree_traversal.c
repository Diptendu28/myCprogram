/*binary tree traversal*/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left,*right;
};

struct node *create()
{
	struct node *temp;
	int data;
	printf("\nEnter data(-1 to stop entering data) : ");
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	printf("\nEnter left child of %d : ",data);
	temp->left=create();
	printf("\nEnter right child of %d : ",data);
	temp->right=create();
	return temp;
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d\t",ptr->data);
		inorder(ptr->right);
	}
}

int main()
{
	struct node *root=NULL;
	int ch;
	do
	{
		printf("\n1. Create Binary Tree");
		printf("\n2. Inorder Traversal");
		printf("\n3. Preorder Traversal");
		printf("\n4. Postorder Traversal");
		printf("\n0. Exit.\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	root=create();
					break;
			case 2:	printf("\n\nInorder Traversal : \n");
					inorder(root); 
					break;
			case 3: printf("\n\nPreorder Traversal : \n");
					preorder(root);
					break;
			case 4: printf("\n\nPostorder Traversal : \n");
					postorder(root);
					break;
			case 0: printf("\nExit....");
					break;
			default:printf("\nWrong choice... try again!!!!");
		}
	}while(ch!=0);
	return 0;
}
