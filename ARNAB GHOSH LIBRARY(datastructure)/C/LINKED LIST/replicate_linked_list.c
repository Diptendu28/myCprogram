#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
typedef struct node{
    char data[SIZE];
    struct node *next;
} node;

node *head = NULL;

void createNode(){
    int n;
    node *ptr, *cptr;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0){
        return ;
    }
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
    }
    printf("Enter data: ");
    scanf("%s", &ptr->data);
    head = ptr;
    for(int i = 2; i <= n; i++){
        cptr = (node*)malloc(sizeof(node));
        if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
        }
        printf("Enter data: ");
        scanf("%s", &cptr->data);
        ptr->next = cptr;
        ptr = cptr;
    }
    ptr->next = NULL;
}

void display(){
    node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("%s -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%s\n", ptr->data);
}


int insertAfter(char item[SIZE], char str[SIZE]){
    node *ptr, *cptr;
    cptr = (node*)malloc(sizeof(node));
    strcpy(cptr->data, str);
    ptr = head;
    while(ptr != NULL){
        if(strcmp(ptr->data, item) == 0){
            cptr->next = ptr->next;
            ptr->next = cptr;
            return 1;
        }
        else
            ptr = ptr->next;
    }
    printf("String Not Found!!!");
    return 0;
}

void replicateNode(int count, char str[SIZE]){
    int flag = 1;
    while(flag && count--){
       flag = insertAfter(str, str);
    }
}


int main(void){
    int num, flag = 1, count;;
    char str[SIZE];
    createNode();
    while (flag){
        printf("\n0 to exit\n1 to replicate\n2 to display\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 0: flag = 0; 
            break ;
            case 1:
                printf("Enter that String to Replicate: ");
                scanf("%s", str);
                printf("Enter the number of replication: ");
                scanf("%d", &count);
                replicateNode(count, str);
            break;
            case 2: display();
            break;
            default: printf("Invalid Input");
        }
    }
    return 0;
}

/*

Write a program to create a linked list containing string value.
Then pass the linked list in a function which will replicate the nodes in the list by n times.
The replicated nodes will be consecutive.


Output 1
-----------
Enter the number of nodes: 3
Enter data: Arnab
Enter data: Akand  
Enter data: Animesh

0 to exit     
1 to replicate
2 to display  
Choose: 1     
Enter that String to Replicate: Arnab
Enter the number of replication: 0

0 to exit     
1 to replicate
2 to display  
Choose: 2     
Arnab -> Akand -> Animesh

0 to exit
1 to replicate
2 to display
Choose: 1
Enter that String to Replicate: Arnab
Enter the number of replication: 2

0 to exit
1 to replicate
2 to display
Choose: 2
Arnab -> Arnab -> Arnab -> Akand -> Animesh

0 to exit
1 to replicate
2 to display
Choose: 1
Enter that String to Replicate: Akand
Enter the number of replication: 1

0 to exit
1 to replicate
2 to display
Choose: 2
Arnab -> Arnab -> Arnab -> Akand -> Akand -> Animesh

0 to exit
1 to replicate
2 to display
Choose: 1
Enter that String to Replicate: Animesh
Enter the number of replication: 2

0 to exit
1 to replicate
2 to display
Choose: 2
Arnab -> Arnab -> Arnab -> Akand -> Akand -> Animesh -> Animesh -> Animesh

0 to exit
1 to replicate
2 to display
Choose: 1
Enter that String to Replicate: Hello
Enter the number of replication: 5
String Not Found!!!
0 to exit
1 to replicate
2 to display
Choose: 0

*/
