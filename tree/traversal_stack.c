/*Tree traversal using stack*/
//#include<stdio.h>
//#include<stdlib.h>
//#define max 20
//int top = -1;
//
//typedef struct node{
//    int data;
//    struct node *left, *right;
//} node;
//
//struct node *stack[max];
//
//int isFull(){
//    if(top == max - 1)
//        return 1;
//    else
//        return 0;
//}
//
//int isEmpty(){
//    if(top == -1)
//        return 1;
//    else
//        return 0;
//}
//
//void push(node *item){
//    if(isFull())
//        return;
//    else
//        stack[++top] = item;
//}
//
//node* pop(){
//    if(isEmpty())
//        return NULL;
//    else
//        return stack[top--];
//}
//
//
//node* create(){
//    node *temp;
//    int data;
//    printf("Enter data(-1 for no data): ");
//    scanf("%d", &data);
//    if(data == -1)
//        return NULL;
//    temp = (node*)malloc(sizeof(node));
//    temp->data = data;
//     printf("Enter Left Child of %d---\n", temp->data);
//    temp->left = create();
//    printf("Enter Right Child %d---\n", temp->data);
//    temp->right = create();
//    return temp;
//}
//
//node* inorder(node *root){
//	node *ptr = root;
//	while (ptr != NULL || !isEmpty()){
//		if (ptr != NULL){
//			push(ptr);
//			ptr = ptr->left;
//		}
//		else{
//			ptr = pop(); 
//			printf("%d ", ptr->data);
//			ptr = ptr->right; 
//		}
//	}
//}
//
//
//node* preorder(node *root){
//	node *ptr = root;
//	if(ptr == NULL)
//        return NULL;
//    push(ptr);
//    while (isEmpty() == 0){
//        ptr = pop(); 
//		printf("%d ", ptr->data);
//        if (ptr->right)
//            push(ptr->right);
//        if (ptr->left)
//            push(ptr->left);
//    }
//}
//
//
//
//
//int main(){
//    node *root = create();
//    printf("inorder: ");
//    inorder(root);
//    printf("\npreorder: ");
//    preorder(root);
//    // printf("\npostorder: ");
//    // postorder(root);
//    return 0;
//}

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

int main(void){
    node *root = NULL;
    int flag = 1;
    while(flag){
        int val;
        printf("\n\n____|[ MENU ]|____");
        printf("\n\n0 to exit\n1 to insert data\n2 for in-order traversal\n3 for pre-oder traversal\n4 for post-order traversal\n\nchoose: ");
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

            default: printf("invalid input!!!");
        }
    }
    return 0;
}
