#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
} node;

node* create(){
    node *temp;
    int data;
    printf("Enter data(-1 for no data): ");
    scanf("%d", &data);
    if(data == -1)
        return NULL;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    printf("Enter Left Child of %d---\n", temp->data);
    temp->left = create();
    printf("Enter Right Child %d---\n", temp->data);
    temp->right = create();
    return temp;
}

void preorder(node* ptr){
    if(ptr != NULL){
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(node *ptr){
    if(ptr != NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void inorder(node *ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

int main(void){
    node *root = create();
    printf("\ninorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);
    return 0;
}

/*
Enter data(-1 for no data): 1
Enter Left Child of 1---    
Enter data(-1 for no data): 2
Enter Left Child of 2---    
Enter data(-1 for no data): 4
Enter Left Child of 4---
Enter data(-1 for no data): -1
Enter Right Child 4---
Enter data(-1 for no data): -1
Enter Right Child 2---
Enter data(-1 for no data): -1
Enter Right Child 1---
Enter data(-1 for no data): 3
Enter Left Child of 3---
Enter data(-1 for no data): 5
Enter Left Child of 5---
Enter data(-1 for no data): 7
Enter Left Child of 7---
Enter data(-1 for no data): -1
Enter Right Child 7---
Enter data(-1 for no data): -1
Enter Right Child 5---
Enter data(-1 for no data): 8
Enter Left Child of 8---
Enter data(-1 for no data): -1
Enter Right Child 8---
Enter data(-1 for no data): -1
Enter Right Child 3---
Enter data(-1 for no data): 6
Enter Left Child of 6---
Enter data(-1 for no data): -1
Enter Right Child 6---
Enter data(-1 for no data): -1

inorder: 4 2 1 7 5 8 3 6
preorder: 1 2 4 3 5 7 8 6
postorder: 4 2 7 8 5 6 3 1


/*


node* findMax(node *ptr){
    if(ptr == NULL)
        return ptr;
    // node* max = ptr;
    // node* lmax = findMax(ptr->left);
    node* rmax = findMax(ptr->right);
    if(lmax->data > max->data)
        max = lmax;
    if(rmax->data > max->data)
        max = rmax;
    return max;
}

node* findMin(node *ptr){
    if(ptr == NULL)
        return ptr;
    node *min = ptr;
    node *lmin = findMax(ptr->left);
    node *rmin = findMax(ptr->right);
    if(lmin->data < min->data)
        min  = lmin ;
    if(rmin->data  < min->data)
        min  = rmin ;
    return min;
}


node* searchValue(node *ptr, int key){
    if(ptr == NULL)
        return ptr;
    if(ptr->data == key)
        return ptr;
    node* temp = NULL;
    if(ptr->left != NULL){
        temp = searchValue(ptr->left, key);
        if(temp != NULL)
            return temp;
    }
    if(ptr->right != NULL){
        temp = searchValue(ptr->right, key);
        if(temp != NULL)
            return temp;
    }
}



*/