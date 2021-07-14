/*Mam this is the working code--
For verification purpose I submitted the code as a private comment.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
};

struct node *head = NULL;

void create(){
    struct node *ptr, *cptr;
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0){
        printf("\nZERO NODES!!!\n");
        return;
    }
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the first data: ");
    scanf("%d", &ptr->data);
    head = ptr;
    for(i = 2; i <= n; i++){
        cptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data no.%d: ", i);
        scanf("%d", &cptr->data);
        ptr->link = cptr;
        ptr = cptr;
    }
    ptr->link = NULL;
}

int search(struct node* ptr, int item){
    int a;
    if(ptr->link == NULL){
        if(ptr->data == item)
            return 1;
        else
            return 0;
    }
    if(ptr->data == item)
            return 1;
    else{
        a = search(ptr->link, item);
        return a;
    }
}

int main()
{
    int a;
    create();
    printf("Enter the item to be searched: ");
    scanf("%d",&a);
    if(search(head, a))
        printf("Element found.\n");
    else
        printf("Element not found\n");
        system("pause");
    return 0;
}



/*Enter the number of nodes: 6

Enter the first data: 7
Enter the data no.2: 4
Enter the data no.3: 2
Enter the data no.4: 8
Enter the data no.5: 9
Enter the data no.6: 5
Enter the item to be searched: 8
Element found.
Press any key to continue . . .*/

















/*#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
};

struct node *head = NULL;

void create(){
    struct node *ptr, *cptr;
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0){
        printf("\nZERO NODES!!!\n");
        return;
    }
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the first data: ");
    scanf("%d", &ptr->data);
    head = ptr;
    for(i = 2; i <= n; i++){
        cptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data no.%d: ", i);
        scanf("%d", &cptr->data);
        ptr->link = cptr;
        ptr = cptr;
    }
    ptr->link = NULL;
}

int search(struct node* ptr, int item){
    int a;
    if(ptr->link == NULL){
        if(ptr->data == item)
            return 1;
        else
            return 0;
    }
    if(ptr->data == item)
            return 1;
    else{
        a = search(ptr->link, item);
        return a;
    }
}

int main()
{
    int a;
    create();
    printf("Enter the item to be searched: ");
    scanf("%d",&a);
    if(search(head, a))
        printf("Element found.\n");
    else
        printf("Element not found\n");
        system("pause");
    return 0;
}

*/




