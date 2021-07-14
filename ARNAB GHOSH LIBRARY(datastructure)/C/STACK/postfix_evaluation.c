#include<stdio.h>
#include<math.h>
#define max 20
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


void push(int x){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    else{
        stack[++top] = x;
    }
}

int pop(){
    if(isEmpty()){
         printf("Stack Underflow\n");
        return 0;
    }
    else{
        return stack[top--];
    }
}


void postfix_evaluation(char *str){
    int x, y, i;
    for(i = 0; str[i]!='\0'; i++){

        switch(str[i]){

            case '+':
                    x = pop();
                    y = pop();
                    push(x + y);
                    break;

            case '-':
                    x = pop();
                    y = pop();
                    push(y - x);
                    break;

            case '*':
                    x = pop();
                    y = pop();
                    push(y * x);
                    break;

            case '/':
                    x = pop();
                    y = pop();
                    push(y / x);
                    break;

            case '^':
                    x = pop();
                    y = pop();
                    push(pow(y,x));
                    break;

            default:
                    push(str[i]-48);
                    break;

        }

    }
    printf("\nThe result of expression %s  =  %d\n\n",str,pop());
}




int main(void){

    char str[20];
    char *ch;
    int x,y,n3,num;
    printf("Enter the postfix expression: ");
    scanf("%s",str);
    postfix_evaluation(str);
    return 0;
}


/*
Enter the expression :: 12+3-21+3^-

The result of expression 12+3-21+3^-  =  -27

*/
