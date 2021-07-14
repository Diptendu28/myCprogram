#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max];
int top = -1;
int isFull(){
    if(top == max - 1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(char x){
    if(isFull())
        return;
    else
        stack[++top] = x;
}


char pop(){
    if(isEmpty())
        return 0;
    else
        return stack[top--];
}

//============================= Stack Ends ============================================


typedef struct node{
    char data;
    struct node *next;
} node;

node *head = NULL;

node* setNode(node *ptr, char data){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void display(node *ptr){
    if(ptr == NULL){
        printf("Nothing to Print\n");
        return ;
    }
    while(ptr->next != NULL){
        printf("%c -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%c\n", ptr->data);
}

node* addNode(char value){
    node *temp,*ptr;
    temp = setNode(temp, value);
    if(head == NULL)
        head = temp;
    else{
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}

node* breakWords(char *word){
    node *ptr;
    for(int i = 0; i < strlen(word); i++){
        ptr = addNode(word[i]);
        push(word[i]);
    }
    return ptr;
}

int checkPalindrom(){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->data != pop())
            return 0;
        ptr = ptr->next;
    }
    return 1;
}


int main(void){
    char word[max];
    node *ptr;
    printf("Enter the Word(max = 100): ");
    gets(word);
    ptr = breakWords(word);
    if(checkPalindrom())
        printf("\nThe linked list is palindrome\n");
    else
        printf("\nThe linked list is not palindrome\n");
    system("pause");
    return 0;
}

/**
Note
-----
I have use a function named "node* breakWords(char *word)"
which convert a character array to a linked list where
each letter of the word is added in a new node.

It also push each letters in the stack at the same time.

Output
-------

Enter the Word(max = 100): radar

The linked list is palindrome
----------------------------------

Enter the Word(max = 100): mother

The linked list is not palindrome
----------------------------------

Enter the Word(max = 100): madam

The linked list is palindrome

*/

