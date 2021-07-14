/*BST inorder,preorder,postorder,indorder,find max,find min,search for a particular element*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
}node;

node* createNode(node *ptr, int no)
{
    ptr = (node*)malloc(sizeof(node));
    ptr->data = no;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

node* insert(node *ptr, int key)
{
    if(ptr == NULL)
	{
        node *temp = createNode(temp, key);
        return temp;
    }
    if(key < ptr->data)
        ptr->left = insert(ptr->left, key);
    else
        ptr->right = insert(ptr->right, key);
    return ptr;
}

void preorder(node* ptr)
{
    if(ptr != NULL)
	{
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(node *ptr)
{
    if(ptr != NULL)
	{
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}
void inorder(node *ptr)
{
    if(ptr != NULL)
	{
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

//node *fimax(node *a)
//{
//	if(a==NULL)
//		return;
//	while(a->right!=NULL)
//		a=a->right;
//	return a;
//}
//node *fimin(node *a)
//{
//	if(a==NULL)
//		return;
//	while(a->left!=NULL)
//		a=a->left;
//	return a;
//}
//
//node *search(node *root,int key)
//{
//	if(root==NULL||root->data==key)
//		return root;
//	if(root->data<key)
//		return search(root->right,key);
//	else
//		return search(root->left,key);
//}
int main(void)
{
    node *root = NULL,*ptr;
    int flag = 1,k;
    while(flag){
        int no;
		printf("\n\n0 to exit\n1 to insert data\n2 for in-order traversal\n3 for pre-oder traversal\n4 for post-order traversal\n5 for max\n6 for min\n7 for search a particular element\n\nchoose: ");
        scanf("%d", &no);
        switch(no)
		{
            case 0:
                    flag = 0;
                    free(root);
            break;
			case 1:
                    printf("Enter the data: ");
                    int data;
                    scanf("%d", &data);
                    root = insert(root, data);
            break;
			case 2: 
                    printf("\ninorder: ");
                    inorder(root);
            break;
			case 3: 
                    printf("\npreorder: ");
                    preorder(root);
            break;
			case 4:
                    printf("\npostorder: ");
                    postorder(root);
            break;
//            case 5:
//            		ptr=fimax(root);
//            		printf("Maximum element %d is found at address %u:\n",ptr->data,ptr);
//            break;
//			case 6:
//            		ptr=fimin(root);
//            		printf("Minimum element %d is found at address %u:\n",ptr->data,ptr);
//            break;
//			case 7:
//					printf("enter the element you want to search\n");
//					scanf("%d",&k);	
//					ptr=search(root,k);
//					if(ptr!=NULL)
//						printf("element found at address %u",ptr);
//					else
//						printf("element not found");
//			break;		
			default: printf("invalid input!!!");
        }
    }
    return 0;
}
