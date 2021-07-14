#include<stdio.h>
#include <stdlib.h>

struct Queue {
   int *queue;
    int front;
    int rear;
} queue = {.front = -1, .rear = -1}; // designated Initialization


struct Queue* createQueue(struct Queue *q, unsigned int size){
    q = &queue;    
    q->queue = (int*)calloc(size, sizeof(int)); 
    return q;
}



int isFull(struct Queue *q, int max){
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



void enQueue(struct Queue *q, int size, int item){
    if(isFull(q, size)){
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
        return -1;
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
    unsigned int size;
    struct Queue *q;
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);    
    q = createQueue(q,size);
    while(1){
        printf("\nMenu:");
        printf("\n1) enqueue\n2) dequeue\n3) is Full?\n4) is Empty?\n5) display\n6) peek the front\n7) Exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);

        switch (num){
            case 1:{
                printf("Enter the value:");
                scanf("%d",&item);
                enQueue(q, size, item);
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
                if(isFull(q, size)){
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
    free(q);
    return 0;
}