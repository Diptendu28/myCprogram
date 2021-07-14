#include<stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *queue;
    int front;
    int rear;
} queue;



typedef struct Stack{
    queue *q1;
    queue *q2;
} stack;



queue* createQueue(queue *q, unsigned int size){
    q->queue = (int*)calloc(size, sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}



int isFull(queue *q, int max){
    if(q->rear == max-1){
        return 1;
    }
    else{
        return 0;
    }
}



int isEmpty(queue *q){
    if(q->front == -1){
        return 1;
    }
    else{
        return 0;
    }
}



void enQueue(queue *q, unsigned int size, int item){
    if(isFull(q, size)){
        return ;
    }
    else if(q->front == -1){
        q->front = 0;
    }
    q->queue[++q->rear] = item;
}



int deQueue(queue *q, unsigned int size){
    if(isEmpty(q)){
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




void display(stack s, unsigned int size){
    int i;
    if(isEmpty(s.q1)){
        printf("\nStack is EMPTY!!!\n");
        return ;
    }
    else{
        printf("\nElements in stack:\n");
        for(i = s.q1->front; i<= s.q1->rear; i++){
           printf("%d ", s.q1->queue[i]);
        }
    }
    printf("\n");
}




void peek(queue *q){
    if(isEmpty(q)){
        printf("\nStack Underflow!!!\n");
        return ;
    }
    else{
        printf("\npeek value is %d\n", q->queue[q->front]);
    }
}



void push(stack s, unsigned int size, int item){
    if(isFull(s.q1, size)){
        printf("\nStack Overflow!!!\n");
        return ;
    }

    else{
        if(isEmpty(s.q1)){
            enQueue(s.q1, size, item);
            printf("\n%d inserted in stack!!!\n", item);
            return ;
        }
        while(!isEmpty(s.q1)){
            enQueue(s.q2, size, deQueue(s.q1, size));
        }
        enQueue(s.q1, size, item);
        while(!isEmpty(s.q2)){
            enQueue(s.q1, size, deQueue(s.q2, size));
        }
        printf("\n%d inserted in stack!!!\n", item);
    }
}



void pop(stack s, unsigned int size){
    if(isEmpty(s.q1)){
        printf("\nStack Underflow!!!\n");
        return ;
    }
    else{
        printf("\n%d deleted from stack\n",deQueue(s.q1, size));
    }
}





int main(void){
    unsigned int size;
    stack s;
    queue Q1, Q2;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    s.q1 = createQueue(&Q1, size);
    s.q2 = createQueue(&Q2, size);

    while(1){
        printf("\n1) PUSH()\n2) POP()\n3) DISPLAY()\n4) PEEK()\n5) IS EMPTY ?\n6) IS FULL ?\n7) EXIT()\n");
        int opt;
        printf("\nOption: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:{
                int item;
                printf("Enter the item: ");
                scanf("%d", &item);
                push(s, size, item);
                break;
            }

            case 2:{
                 pop(s, size);
                break;
            }

            case 3:{
                display(s, size);
                break;
            }

            case 4:{
                peek(s.q1);
                break;
            }

            case 5:{
                if(isEmpty(s.q1)){
                    printf("\nStack is Empty!!!\n");
                }
                else{
                    printf("\nStack is not Empty!!!\n");
                }
                break;
            }

            case 6:{
                if(isFull(s.q1, size)){
                    printf("\nStack is Full!!!\n");
                }
                else{
                    printf("\nStack is not Full!!!\n");
                }
                break;
            }

            case 7:{
                free(s.q1);
                free(s.q2);
                exit(1);
                break;
            }

            default: printf("\nInvalid Entry!!!\n");
        }

    }

    free(s.q1);
    free(s.q2);
    return 0;
}



/**
To construct a stack using two queues (q1, q2), we need to simulate the stack operations by using queue operations:

push (E element)
if q1 is empty, enqueue E to q1
if q1 is not empty, enqueue all elements from q1 to q2, then enqueue E to q1, and enqueue all elements from q2 back to q1
pop
dequeue an element from q1
As we see, q1 acts as the main source for the stack, while q2 is just a helper queue that we use to preserve the order expected by the stack.
*/

