/*Binary search tree insertion,traversal,find max & min node,search node,delete node,height of BST*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left,*right;
};

struct node *insert(struct node *ptr,int key)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->data=key;
	if(ptr==NULL)
		return temp;
	else if(key<ptr->data)
		ptr->left = insert(ptr->left,key);
	else
		ptr->right = insert(ptr->right,key);	
	return ptr;
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d\t",ptr->data);
		inorder(ptr->right);
	}
	else
		return;
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	else
		return;
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);
	}
	else
		return;
}

struct node *findmax(struct node *ptr)
{
	if(ptr==NULL)
		return;
	while(ptr->right!=NULL)
		ptr=ptr->right;
	return ptr;
}

struct node *findmin(struct node *ptr)
{
	if(ptr==NULL)
		return;
	while(ptr->left!=NULL)
		ptr=ptr->left;
	return ptr;
}

struct node *search_key(struct node **curr,int key,struct node **parent)
{
	while((*curr)!=NULL && (*curr)->data!=key)
	{
		*parent=*curr;
		if(key<(*curr)->data)
			(*curr)=(*curr)->left;
		else
			*curr=(*curr)->right;
	}
}

struct node *del(struct node **root,int key)
{
	int val;
	struct node *parent=NULL;
	struct node *curr=*root;
	search_key(&curr,key,&parent);
	if(curr==NULL)
		return;
	//when the node to be deleted has no children, i.e. it is a leaf node
	if(curr->left==NULL && curr->right==NULL)
	{
		if(curr!=*root)
		{
			if(parent->left==curr)
				parent->left=NULL;
			else
				parent->right=NULL;
		}
		else
			*root=NULL;
		free(curr);
	}
	//when the node to be deleted has two children
	else if(curr->left && curr->right)
	{
		struct node *successor = findmin(curr->right);
		val = successor->data;
		del(root,successor->data);
		curr->data=val;
	}
	//when the node to be deleted has only one child
	else
	{
		struct node *child=(curr->left)?(curr->left):(curr->right);
		if(curr!=*root)
		{
			if(curr==parent->left)
				parent->left=child;
			else
				parent->right=child;
		}
		else
			*root=child;
		free(curr);
	}
}

int find_height(struct node *ptr)
{
	struct node *root=ptr;
	if(root==NULL)
		return 0;
	else
	{
		int left_height=0, right_height=0;
		if(ptr->left!=NULL)
			left_height=find_height(ptr->left);
		if(ptr->right!=NULL)
			right_height=find_height(ptr->right);
		int max=(left_height>right_height)?left_height:right_height;
		return (max+1);
	}
}

int main()
{
	struct node *root, *parent, *ptr, *curr, *temp;
	root=parent=NULL;
	int ch,key;
	do
	{
		printf("\n\n -----Binary Search Tree-----\n");
		printf("\n1. Insert a Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Find Maximum Node");
		printf("\n6. Find Minimum Node\n7. Search An Element\n8. Delete a Node\n9. Find Height of BST\n0. Exit.\n");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	printf("\nEnter the value to insert : ");
					scanf("%d",&key);
					root=insert(root,key);
					break;
			case 2:	printf("\nInorder Traversal : \n");
					inorder(root); 
					break;
			case 3: printf("\nPreorder Traversal : \n");
					preorder(root);
					break;
			case 4: printf("\nPostorder Traversal : \n");
					postorder(root);
					break;
			case 5: ptr=findmax(root);
					printf("\nThe Maximum value is %d which is stored in the address %u.\n",ptr->data,ptr);
					break;
			case 6:	ptr=findmin(root);
					printf("\nThe Minimum value is %d which is stored in the address %u.\n",ptr->data,ptr);
					break;
			case 7: printf("\nEnter the value to search : ");
					scanf("%d",&key);
					curr=root;
					ptr=search_key(&curr,key,&parent);
					if(ptr!=NULL)
						printf("\n The Node %d is present in the address %u.",curr->data,curr);
					else
						printf("\n The Node %d is not present in the BST.",key);
					break;
			case 8: printf("\n Enter the value to delete : ");
					scanf("%d",&key);
					temp=del(&root,key);
					if(temp!=NULL)
						printf("\n The %d node is deleted",key);
					else
						printf("\n The Node %d is not present in the BST.",key);
					break;
			case 9:	printf("\n The height of the BST is : %d",find_height(root));
					break;
			case 0: printf("\n Exit....\n");
					break;
			default:printf("\n Wrong choice... try again!!!!\n");
					break;
		}
	}
	while(ch!=0);
	return 0;
}
