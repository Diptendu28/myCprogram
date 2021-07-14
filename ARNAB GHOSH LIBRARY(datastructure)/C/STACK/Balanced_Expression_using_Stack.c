#include<stdio.h>
#include<string.h>
#define max 50

struct Stack{
    char stack[max];
    int top;
} s = {.top = -1};//designated initialization


int isEmpty(){
    if(s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(s.top == max - 1){
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


int checkPair(char exp1, char exp2){
    if (exp1 == '(' && exp2 == ')')
        return 1;
    else if (exp1 == '{' && exp2 == '}')
        return 1;
    else if (exp1 == '[' && exp2 == ']')
        return 1;
    else
        return 0;
}
void checkExpression(char *exp){
    int i;
    for(i = 0; exp[i] !='\0'; i++){
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

            if (isEmpty()){
                printf("The Expression is not Balanced.");
                return ;
            }
            if(!checkPair(pop(), exp[i])){
                printf("The Expression not Balanced.");
                return ;
            }
        }
    }

    if (isEmpty())
       printf("The Expression Balanced.");
    else
        printf("The Expression not Balanced.");
}



int main(void){
    char exp[max];
    printf("Enter the expression(<=%d): ", max);
    gets(exp);
    checkExpression(exp);
    system("pause");
    return 0;
}

//A+B*(C-D)/E
//((a+b)-c*(d/e))+f
//(a+b*c-d)/(e*f)
//A+(B*C-(D/E^F)*G)*H

