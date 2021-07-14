#include<stdio.h>
#include <stdlib.h>
#define max 5
struct Queue {
   int queue[max];
    int front;
    int rear;
}q = {.front = -1, .rear = -1}; // designated Initialization



int isFull(){
    if(q.rear == max-1){
        return 1;
    }
    else{
        return 0;
    }
}



int isEmpty(){
    if(q.front == -1){
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
    else if(q.front == -1){
        q.front = 0; // front++;
    }
    q.queue[++q.rear] = item;
    printf("%d is inserted!\n", item);
}




int deQueue(){
    if(isEmpty()){
        printf("Queue Underflow!!!");
        return -1; //return -9999;
    }
    int val = q.queue[q.front];
    if(q.front == q.rear){
        q.front = q.rear = -1;
    }
    else{
        q.front++;
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
        for(int i = q.front; i <= q.rear; i++)       
            printf("%d ", q.queue[i]);
    }
}




void peek(){
    if(isEmpty()){
        printf("Queue Underflow!!!");
        return ; 
    }  
    else{
        printf("peek value is %d", q.queue[q.front]);
    }
}





int main(void){
    int num, item;
    /*q.front = -1;
    q.rear = -1;*/
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