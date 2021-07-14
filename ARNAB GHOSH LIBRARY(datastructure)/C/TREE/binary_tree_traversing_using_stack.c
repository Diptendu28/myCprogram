#include<stdio.h>
#include<stdlib.h>
#include"printIO.h"
#define max 20
int top = -1;

typedef struct node{
    int data;
    struct node *left, *right;
} node;

struct node *stack[max];

int isFull(){
    if(top == max - 1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}


void push(node *item){
    if(isFull())
        return;
    else
        stack[++top] = item;
}

node* pop(){
    if(isEmpty())
        return NULL;
    else
        return stack[top--];
}


node* create(){
    node *temp;
    int data;
    //printf("Enter data(-1 for no data): ");
    scanf("%d", &data);
    if(data == -1)
        return NULL;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    // printf("Enter Left Child of %d---\n", temp->data);
    temp->left = create();
    //printf("Enter Right Child %d---\n", temp->data);
    temp->right = create();
    return temp;
}

void inorder(node *root){ // left -> root -> right
	node *ptr = root;
	while (ptr != NULL || !isEmpty()){
		if (ptr != NULL){
			push(ptr);
			ptr = ptr->left;
		}
		else{
			ptr = pop(); 
			printf("%d ", ptr->data);
			ptr = ptr->right; 
		}
	}
}


void preorder(node *root){ // root -> left -> right
	node *ptr = root;
	if(ptr == NULL)
        return ;
    push(ptr);
    while (isEmpty() == 0){
        ptr = pop(); 
		printf("%d ", ptr->data);
        if (ptr->right)
            push(ptr->right);
        if (ptr->left)
            push(ptr->left);
    }
}

void postorder(node *root){ // left->right->root
    node *prev = NULL;
    do{
        while(root != NULL){
            push(root);
            root = root->left;
        }
        while(root == NULL && !isEmpty()){
            root = stack[top];
            if(root->right == NULL || root->right == prev){
                printf("%d ", root->data);
                pop();
                prev = root;
                root = NULL;
            }
            else
                root = root->right;
        }

    } while(!isEmpty());
}



int main(void){
    OpenIO(fopen("binary_tree.c", "a"));
    node *root = create();
    printf("inorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);
    return 0;
}

/*
inorder: 4 2 1 7 5 8 3 6 
preorder: 1 2 4 3 5 7 8 6 
postorder: 4 2 7 8 5 6 3 1 (due task)

1
2
4
-1
-1
-1
3
5
7
-1
-1
8
-1
-1
6
-1
-1


inorder: 5 7 20 30 10 2 40 
preorder: 10 20 5 7 30 40 2 
10
20
5
-1
7
-1
-1
30
-1
-1
40
2
-1
-1
-1

*/