#include<stdio.h>
#include <stdlib.h>

struct Deque{
    int *queue;
    int front;
    int rear;
} deque = {.front = -1, .rear = -1};


struct Deque* createDeque(struct Deque *dq, unsigned int size){
    dq = &deque;
    dq->queue = (int*)calloc(size, sizeof(int));
    if(dq->queue == NULL){
        printf("\nMemory Not Allocated!!!\n");
        return NULL;
    }
    return dq;
}



int isFull(struct Deque *dq, int max){
    if((dq->front == 0 && dq->rear == max-1)||(dq->front == dq->rear + 1)){
        return 1;
    }
    else{
        return 0;
    }
}


int isEmpty(struct Deque *dq){
    if(dq->front == -1 && dq->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}



void enQueue_Front(struct Deque *dq, int size, int item){
    if(isFull(dq, size)){
        printf("Queue Overflow!!!");
        return ;
    }
    if(dq->front == -1 && dq->rear == -1){
        dq->front = dq->rear = 0;
    }
    else{
        dq->front = (dq->front-1+size)%size;
    }
    dq->queue[dq->front] = item;
    printf("%d is inserted!\n", item);

}



void enQueue_Rear(struct Deque *dq, int size, int item){
    if(isFull(dq,size)){
        printf("Queue Overflow!!!");
        return ;
    }
    if(dq->front == -1 && dq->rear == -1){
        dq->front = dq->rear = 0;
    }
    else{
        dq->rear = (dq->rear+1)%size;
    }
    dq->queue[dq->rear] = item;
    printf("%d is inserted!\n", item);

}



void deQueue_Front(struct Deque *dq, int size){
    if(isEmpty(dq)){
        printf("Queue Underflow!!!");
        return ;
    }

    if(dq->front == dq->rear){
        printf("deleted item = %d", dq->queue[dq->front]);
        dq->front = -1;
        dq->rear = -1;
    }

    else{
        printf("deleted item = %d", dq->queue[dq->front]);
        dq->front = (dq->front+1)%size;
    }
}



void deQueue_Rear(struct Deque *dq, int size){
    if(isEmpty(dq)){
        printf("Queue Underflow!!!");
        return ;
    }

    if(dq->front == dq->rear){
        printf("deleted item = %d", dq->queue[dq->front]);
        dq->front = -1;
        dq->rear = -1;
    }

    else{
        printf("deleted item = %d", dq->queue[dq->rear]);
        dq->rear = (dq->rear-1+size)%size;
    }
}



void display(struct Deque *dq, int size){
    int i;
    if(isEmpty(dq)){
        printf("Queue Underflow!!!");
        return ;
    }
    else{
        printf("\nElements in queue:\n");
        for(i = dq->front; i != dq->rear; i=(i+1)%size){
           printf("%d ", dq->queue[i]);
        }
        printf("%d", dq->queue[i]);
    }
}




void peek(struct Deque *dq){
    if(isEmpty(dq)){
        printf("Queue Underflow!!!");
        return ;
    }
    else{
        printf("peek value is %d", dq->queue[dq->front]);
    }
}



void inputRestricted(struct Deque *dq, int size){
    int val, item, flag = 1;
    while(flag){
      printf("\n1) insert rear\n2) delete front\n3) delete rear\n4) main menu\n5) display\n");
      printf("\nChoose: ");
      scanf("%d", &val);
      switch(val){
        case 1:{
            printf("Enter the item: ");
            scanf("%d", &item);
            enQueue_Rear(dq, size, item);
        }
        break;
        case 2: deQueue_Front(dq, size); break;
        case 3: deQueue_Rear(dq, size); break;
        case 4: flag = 0; break;
        case 5: display(dq, size); break;
        default: printf("Invalid Entry!!!");
      }
    }
    return ;
}


void outputRestricted(struct Deque *dq, int size){
    int val, item, flag = 1;
    while(flag){
      printf("\n1) insert front\n2) insert rear\n3) delete front\n4) main menu\n5) display\n");
      printf("\nChoose: ");
      scanf("%d", &val);
      switch(val){
        case 1:{
            printf("Enter the item: ");
            scanf("%d", &item);
            enQueue_Front(dq, size, item);
        }
        break;
        case 2:{
            printf("Enter the item: ");
            scanf("%d", &item);
            enQueue_Rear(dq, size, item);
        }
        break;
        case 3: deQueue_Front(dq, size); break;
        case 4: flag = 0; break;
        case 5: display(dq, size); break;
        default: printf("Invalid Entry!!!");
      }
    }
    return ;
}




int main(void){
    int num, item;
    unsigned int size;
    struct Deque *dq;
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);
    dq = createDeque(dq,size);
    while(1){
        printf("\nMenu:");
        printf("\n1) input restricted\n2) output restricted\n3) is Full?\n4) is Empty?\n5) display\n6) peek the front\n7) Exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);

        switch (num){
            case 1: inputRestricted(dq, size); break;

            case 2: outputRestricted(dq, size); break;

            case 3:{
                if(isFull(dq, size)){
                    printf("Queue Overflow\n");
                }
                else{
                    printf("Queue is not Full\n");
                }
            }
            break;

            case 4:{
                if(isEmpty(dq)){
                    printf("Queue underflow\n");
                }
                else{
                    printf("Queue is not Empty\n");
                }
            }
            break;

            case 5:{
                display(dq, size);
            }
            break;

            case 6:{
                peek(dq);
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
    free(dq);
    return 0;
}

/**
input restricted
insert -> rear
delete -> rear and front

output restricted
insert -> rear and front
delete -> front

*/
