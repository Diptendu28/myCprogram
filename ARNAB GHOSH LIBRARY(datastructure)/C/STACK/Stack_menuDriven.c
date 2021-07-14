#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
int stack[max];
int top = -1;

int isFull(){
    if(top == max - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int item){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    else{
        stack[++top] = item;
        printf("Element %d pushed", item);
    }
}

void pop(){
    if(isEmpty()){
         printf("Stack Underflow\n");
        return ;
    }
    else{
        printf("Element %d poped", stack[top--]);
    }
}

void display(int arr[max], int len){
    if(isEmpty()){
        printf("Stack is empty.");
    }
    else{
        printf("The full stack is:\n");
        for(int i = top; i >= 0; i--){
            printf("%d ", arr[i]);
        }
    }

}

void peek(){
    if(isEmpty()){
        printf("Stack is empty.");
    }
    else{
        printf("top: %d", stack[top]);
    }

}


int main(void){
    int num;
    int val;
    while(1){
        printf("\nMenu:");
        printf("\n1) push\n2) pop\n3) is Full?\n4) is Empty?\n5) display\n6) peek the top\n7) exit\n");

        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop(); break;

            case 3:
                if(isFull()){
                    printf("Stack is Full\n");
                }
                else{
                    printf("Stack is not Full\n");
                }
                break;

            case 4:
                if(isEmpty()){
                    printf("Stack is Empty\n");
                }
                else{
                    printf("Stack is not Empty\n");
                }
                break;
            case 5: display(stack, sizeof(stack)/sizeof(int)); break;

            case 6: peek(); break;

            case 7: exit(0); break;

            default: printf("Invalid Input"); break;
        }
    }
    return 0;
}
