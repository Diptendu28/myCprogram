#include<stdio.h>
#include <stdlib.h>
#define max 5
int queue[max];
int front = -1;
int rear = -1;

int isFull(){
    if(rear == max-1){
        return 1;
    }
    else{
        return 0;
    }
}



int isEmpty(){
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}




void enQueue(int item){
    if(isFull()){
        printf("Queue Overflow!!!");
        return ;
    }
    else if(front == -1){
        front = 0; // front++;
    }
    queue[++rear] = item;
    printf("%d is inserted!\n", item);
}




int deQueue(){
    if(isEmpty()){
        printf("Queue Underflow!!!");
        return -1; //return -9999;
    }
    int val = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return val;
}



void display(){
    if(isEmpty()){
        printf("Queue Underflow!!!");
        return ; 
    }  
    else{
        printf("\nElements in queue:\n");
        for(int i = front; i <= rear; i++)       
            printf("%d ", queue[i]);
    }
}



void peek(){
    if(isEmpty()){
        printf("Queue Underflow!!!");
        return ; 
    }  
    else{
        printf("peek value is %d", queue[front]);
    }
}



int main(void){
    int num, item;
    while(1){
        printf("\nMenu:");
        printf("\n1) enqueue\n2) dequeue\n3) is Full?\n4) is Empty?\n5) display\n6) peek the front\n7) Exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);

        switch (num){
            case 1:{
                printf("Enter the value:");
                scanf("%d",&item);
                enQueue(item);
            }
            break;

            case 2:{
                item = deQueue();
                if(item>0){
                    printf("%d is deleted from the queue!", item);
                }
            }
            break;

            case 3:{
                if(isFull()){
                    printf("Queue Overflow\n");
                }
                else{
                    printf("Queue is not Full\n");
                }                
            }
            break;

            case 4:{
                if(isEmpty()){
                    printf("Queue underflow\n");
                }
                else{
                    printf("Queue is not Empty\n");
                }   
            }
            break;

            case 5:{
                display();
            }
            break;

            case 6:{
                peek();
            }
            break;

            case 7:{
                exit(0);
            }
            break;


            default:{
                printf("Invalid Entry!!!");
            }
            break;
        }
    }
    
    return 0;
}