#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
} node;

node* createNode(node *ptr, int val){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

node* insert(node *ptr, int key){
    if(ptr == NULL){
        node *temp = createNode(temp, key);
        return temp;
    }
    if(key < ptr->data)
        ptr->left = insert(ptr->left, key);
    else
        ptr->right = insert(ptr->right, key);
    return ptr;
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

node* findMax(node *ptr){
    node* temp = ptr;
    while(temp->right != NULL)
        temp = temp->right;
    return temp;
}

node* findMin(node *ptr){
    node* temp = ptr;
    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}


node* searchValue(node *ptr, int key){
    if(ptr == NULL)
        return ptr;
    if(ptr->data == key)
        return ptr;
    if(key < ptr->data)
        return searchValue(ptr->left, key);
    if(key > ptr->data)
        return searchValue(ptr->right, key);
}

// void searchKey(node **curr, node **parent, int key){
//     while((*curr) != NULL && (*curr)->data != key){
//         *parent = *curr;
//         if((*curr)->data > key)
//             *curr = (*curr)->left;
//         else
//             *curr = (*curr)->right;
//     }
// }

// void deleteNode(node **root,int item){
// 	int val;
// 	node *parent=NULL,*curr=*root,*succ,*child;
// 	searchKey(&curr,&parent,item);
// 	if(curr==NULL)
// 	    return;
// 	if(curr->left==NULL && curr->right==NULL){
// 		if(curr!=*root){
// 			if(parent->left==curr)
// 			    parent->left=NULL;
// 			else
// 			    parent->right=NULL;
// 		}
// 		else
// 		    *root=NULL;
// 		free(curr);
// 	}
// 	else if (curr->left && curr->right){  
//         succ  = findMin(curr->right);  
//         val = succ->data;  
//         deleteNode(root, succ->data);  
//         curr->data = val;  
//     }  
//     else{  
//         child = (curr->left)? curr->left: curr->right;   
//         if (curr != *root){  
//             if (curr == parent->left)  
//                 parent->left = child;  
//             else  
//                 parent->right = child;  
//         }   
//         else  
//             *root = child;  
//         free(curr);  
//     }    
// }  
    

void searchKey(node **curr, int key, node **parent){
    while(*curr != NULL && (*curr)->data != key){
        *parent = *curr;
        if(key < (*curr)->data)
            *curr = (*curr)->left;
        else
            *curr = (*curr)->right;
    }
}

void deleteNode(node **root, int key){
    node *parent = NULL, *curr = *root;
    searchKey(&curr, key, &parent);
    if(curr == NULL)
        return;
    if(curr->left == NULL && curr->right == NULL){
        if(curr != *root){
            if(parent->left == curr)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            *root = NULL;
        free(curr);
    }
    else if(curr->left&&curr->right){
        node *succ = findMin(curr->right);
        int val = succ->data;
        deleteNode(root, succ->data);
        curr->data = val;
    }
    else{
        node *child = (curr->left)? curr->left: curr->right;
        if(curr != *root){
            if(curr == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            *root = child;
        free(child);
    }
}


int main(void){
    node *root = NULL, *ptr;
    int flag = 1;
    while(flag){
        int val;
        printf("\n\n__________|[ MENU ]|__________");
        printf("\n\n0 to exit\n1 to insert data\n2 for in-order traversal\n3 for pre-oder traversal\n4 for post-order traversal\n5 for max value\n6 for min value\n7 to search\n8 to delete\n\nchoose: ");
        scanf("%d", &val);
        switch(val){
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

            case 5:
                    ptr = findMax(root);
                    if(ptr != NULL)
                        printf("The max value %d is at %u", ptr->data, ptr);
                    else 
                        printf("Empty Tree!!!");
            break;

            case 6:
                    ptr = findMin(root);
                    if(ptr != NULL)
                        printf("The min value %d is at %u", ptr->data, ptr);
                    else 
                        printf("Empty Tree!!!");
            break;

            case 7: 
                    if(root != NULL){
                        int key;
                        printf("Enter the value: ");
                        scanf("%d", &key);
                        ptr = searchValue(root, key);
                        if(ptr != NULL)
                            printf("The value %d is at %u", ptr->data, ptr);
                        else 
                            printf("%d is not present!!!", key);
                    }
                    else 
                        printf("Empty Tree!!!");
                    
            break;

            case 8: 
                    printf("Enter the value: ");
                    int key;
                    scanf("%d", &key);
                    deleteNode(&root, key);
            break;

            default: printf("invalid input!!!");
        }
    }
    return 0;
}

/*

the given BST is
                        (30)
                       /     \
                      /       \
                     /         \
                   (20)        (39)
                  /    \       /    \
                (10)   (25)  (35)  (42)
                  \     /
                 (15) (23)
inorder: 10 15 20 23 25 30 35 39 42
preorder: 30 20 10 15 25 23 39 35 42
postorder: 15 10 23 25 20 35 42 39 30


Output
--------

__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal  
3 for pre-oder traversal  
4 for post-order traversal

choose: 1
Enter the data: 30


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal      
3 for pre-oder traversal      
4 for post-order traversal    

choose: 1
Enter the data: 20


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal      
3 for pre-oder traversal      
4 for post-order traversal    

choose: 1
Enter the data: 39


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 10


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 25


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 15


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 23


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 35


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 1
Enter the data: 42


__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 2

inorder: 10 15 20 23 25 30 35 39 42

__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 3

preorder: 30 20 10 15 25 23 39 35 42

__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 4

postorder: 15 10 23 25 20 35 42 39 30

__________|[ MENU ]|__________

0 to exit
1 to insert data
2 for in-order traversal
3 for pre-oder traversal
4 for post-order traversal

choose: 0

*/