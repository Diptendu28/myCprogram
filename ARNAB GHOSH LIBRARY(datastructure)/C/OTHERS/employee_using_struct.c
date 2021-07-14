#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct employee{
    int id;
    char name[20];
    char desig[20];
    int salary;
    int year;
} employee;

int main(void){
    int highesPaid, seniorMost;
    int members;
    employee *emp; 
    printf("Enter the number of employees: ");
    scanf("%d", &members);
    
    emp = (employee *)calloc(members, sizeof(employee));
    
    
    for(int i = 0; i < members; i++){
        printf("Employee[%d]:\n", i+1);
        printf("Enter ID: ");
        scanf("%d",&emp[i].id);
        fflush(stdin);
        printf("Enter Name: ");
        scanf("%[^\n]%*c",&emp[i].name);
        printf("Enter Desig: ");
        scanf("%[^\n]%*c",&emp[i].desig);
        printf("Enter Salary: ");
        scanf("%d",&emp[i].salary);
        printf("Enter Year: ");
        scanf("%d",&emp[i].year);
    }

    highesPaid = emp[0].salary;
    seniorMost = emp[0].year;

    
    for(int i = 1; i < members; i++){
        if(highesPaid < emp[i].salary){
            highesPaid = emp[i].salary;
        }
        if(seniorMost > emp[i].year){
            seniorMost = emp[i].year;
        }

    }

    printf("Employee Chart:-\n");        
    for(int i = 0; i < members; i++){
        printf("Employee[%d]:\n",i+1);
        printf("------------------\n");
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Desig: %s\n", emp[i].desig);
        printf("Salary: %d\n", emp[i].salary);
        printf("Year: %d\n", emp[i].year);

    }


    for(int i = 0; i < members; i++)
        if(highesPaid == emp[i].salary)
            printf("The name of the highest paid employee is %s\n", emp[i].name);
            
     for(int i = 0; i < members; i++)
        if(seniorMost == emp[i].year)            
            printf("The name of the senior most employee is %s\n", emp[i].name);
    
    
    
    return 0;
}
