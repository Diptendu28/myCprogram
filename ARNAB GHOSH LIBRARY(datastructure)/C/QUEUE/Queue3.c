#include<stdio.h>
#include <stdlib.h>
#define max 5
struct Queue {
   int queue[max];
    int front;
    int rear;
}; //q = {.front = -1, .rear = -1}; // designated Initialization



int isFull(struct Queue *q){
    if(q->rear == max-1){
        return 1;
    }
    else{
        return 0;
    }
}



int isEmpty(struct Queue *q){
    if(q->front == -1){
        return 1;
    }
    else{
        return 0;
    }
}



void enQueue(struct Queue *q, int item){
    if(isFull(q)){
        printf("Queue Overflow!!!");
        return ;
    }
    else if(q->front == -1){
        q->front = 0; // front++;
    }
    q->queue[++q->rear] = item;
    printf("%d is inserted!\n", item);
}




int deQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow!!!");
        return -1; //return -9999;
    }
    int val = q->queue[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front++;
    }
    return val;
}




void display(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow!!!");
        return ; 
    }  
    else{
        printf("\nElements in queue:\n");
        for(int i = q->front; i <= q->rear; i++)       
            printf("%d ", q->queue[i]);
    }
}




void peek(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow!!!");
        return ; 
    }  
    else{
        printf("peek value is %d", q->queue[q->front]);
    }
}





int main(void){
    int num, item;
    struct Queue queue;
    struct Queue *q = &queue;
    q->front = -1;
    q->rear = -1;
    while(1){
        printf("\nMenu:");
        printf("\n1) enqueue\n2) dequeue\n3) is Full?\n4) is Empty?\n5) display\n6) peek the front\n7) Exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);

        switch (num){
            case 1:{
                printf("Enter the value:");
                scanf("%d",&item);
                enQueue(q,item);
            }
            break;

            case 2:{
                item = deQueue(q);
                if(item>0){
                    printf("%d is deleted from the queue!", item);
                }
            }
            break;

            case 3:{
                if(isFull(q)){
                    printf("Queue Overflow\n");
                }
                else{
                    printf("Queue is not Full\n");
                }                
            }
            break;

            case 4:{
                if(isEmpty(q)){
                    printf("Queue underflow\n");
                }
                else{
                    printf("Queue is not Empty\n");
                }   
            }
            break;

            case 5:{
                display(q);
            }
            break;

            case 6:{
                peek(q);
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