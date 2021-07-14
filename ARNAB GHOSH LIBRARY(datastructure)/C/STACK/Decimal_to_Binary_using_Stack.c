#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
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
        return;
    }
    else{
        stack[++top] = item;
    }
}

int pop(){
    if(isEmpty()){
        return -1;
    }
    else{
        return stack[top--];
    }    
}


void DecToBin(int num){
        int rem;
        if(num == 0){
            printf("0");
            return ;
        }
        while(num != 0){
                rem = num % 2;
                push(rem);
                num/=2;
        }
        while(top != -1){
             printf("%d", pop());
        }
        printf("\n");
}


int main(void){
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        DecToBin(num);
        return 0;
 
}
 
