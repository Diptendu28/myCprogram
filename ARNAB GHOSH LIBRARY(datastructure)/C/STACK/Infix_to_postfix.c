#include<stdio.h>
#include<string.h>
#define max 50

struct Stack{
    char stack[max];
    int top;
} s = {.top = -1};//designated initialization

int isFull(){
    if(s.top == max - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char item){
    if(isFull()){
        return;
    }
    else{
        s.stack[++s.top] = item;
    }
}

char pop(){
    if(isEmpty()){
         return 0;
    }
    else{
        char ch = s.stack[s.top];
        s.top--;
        return ch;
    }
}


int inStackPriority(char ch){
    if(ch =='(')
        return 0;
    if(ch=='+'|| ch =='-')
        return 2;
    if(ch=='*'|| ch =='/')
        return 4;
    else
        return 5;
}

int inComingkPriority( char ch){
    if(ch =='(')
        return 0;
    if(ch=='+'|| ch =='-')
        return 1;
    if(ch=='*'|| ch =='/')
        return 3;
    else
        return 6;
}

void infixTopstfix(char *infix){
    printf("The infix expression: %s\n",infix);
    char symbol, postfix[max], ch;
    int index = 0, pos = 0;
    while(infix[index]!='\0'){
        symbol = infix[index];
        switch (symbol){
            case '(':{
                push(symbol);
            }
            break;

            case ')':{
                ch = pop();
                while(ch!='('){
                    postfix[pos++]= ch;
                    ch = pop();
                }
            }
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':{
                 while (!isEmpty() && inComingkPriority(symbol) <= inStackPriority(s.stack[s.top])){
                    postfix[pos++] = pop();
                 }
                 push(symbol);
            }
            break;

            default:{
                postfix[pos++]=symbol;
            }
        }
        index++;
    }
    while(!isEmpty()){
       postfix[pos++] = pop();
    }
    postfix[pos] = '\0';
    printf("The postfix expression: %s\n", postfix);
}



int main(void){
    char exp[max];
    printf("Enter the infix expression(<=%d): ", max);
    gets(exp);
    infixTopstfix(exp);
    return 0;
}

//A+B*(C-D)/E
//((a+b)-c*(d/e))+f
//(a+b*c-d)/(e*f)
//A+(B*C-(D/E^F)*G)*H

