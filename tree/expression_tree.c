#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

typedef struct node{
    char data;
    struct node *left, *right;
} node;
struct node *stack[max];
int top = -1;

int isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
        return 1;
    else
        return 0;
}

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


node* create_tree(node *root, char postfix[max]){
    node *t, *t1, *t2;
    int i;
    for(i = 0; i < strlen(postfix); i++){
        if(!isOperator(postfix[i])){
            t = (node*)malloc(sizeof(node));
            t->data = postfix[i];
            t->left = NULL;
            t->right = NULL;
            push(t);            
        }
        else{
            t = (node*)malloc(sizeof(node));
            t->data = postfix[i];
            t1 = pop();
            t2 = pop();
            t->right = t1;
            t->left = t2;
            push(t);
        }
    }
    root = pop();
    return root;
}

void preorder(node* ptr){
    if(ptr != NULL){
        printf("%c ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(node *ptr){
    if(ptr != NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%c ", ptr->data);
    }
}

void inorder(node *ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        printf("%c ", ptr->data);
        inorder(ptr->right);
    }
}

int main(void){
    node *root = NULL;
    char str[max];
    printf("Enter the expression: ");
    gets(str);
    puts(str);
    root = create_tree(root, str);
    printf("\npreorder: ");
    preorder(root);
    printf("\ninorder: ");
    inorder(root);
    printf("\npostorder: ");
    postorder(root);
}
