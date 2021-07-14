#include<stdio.h>
int main(void){
    int var = 10;
    int *ptr;
    int **dptr;
    ptr = &var;
    dptr = &ptr;
    //dptr = ptr;
    printf("var:    %d\n",var);
    printf("&var:   %d\n",&var);
    printf("ptr:    %d\n",ptr);
    printf("&ptr:   %d\n",&ptr);
    printf("*ptr:   %d\n",*ptr);
    printf("*&ptr:  %d\n",*&ptr);
    printf("&*ptr:  %d\n",&*ptr);
    printf("dptr:   %d\n",dptr);
    printf("&dptr:  %d\n",&dptr);
    printf("*dptr:  %d\n",*dptr);
    printf("&*dptr: %d\n",&*dptr);
    printf("*&dptr: %d\n",*&dptr);
    printf("**dptr: %d\n",**dptr);
    printf("&**dptr:%d\n",&**dptr);
    printf("**&dptr:%d\n",**&dptr);
    printf("*&*dptr:%d\n",*&*dptr);
    printf("*&*&dptr:%d\n",*&*&dptr);
    printf("&*&*dptr:%d\n",&*&*dptr);
    printf("&**&dptr:%d\n",&**&dptr);
    printf("&*&*&dptr:%d\n",&*&*&dptr);
    return 0;
}


        var:    10          value of var
       &var:    6422300     address of var
        ptr:    6422300     value of ptr -> address of var
       &ptr:    6422296     address of ptr
       *ptr:    10          value at address ptr = value at address(value of ptr) = value at address(6422300) = value at address(&var) = value of var
      *&ptr:    6422300     value at address(adress of ptr) = value at address(6422296) = value of ptr -> address of var
      &*ptr:    6422300     address of(value at address ptr) = address of(10) = &var
       dptr:    6422296     value of dptr -> address of ptr
      &dptr:    6422292     address of dptr
      *dptr:    6422300     value at address dptr = value at address(value of dptr) = value at address(6422296) = value at address(&ptr) = value of ptr
     &*dptr:    6422296     address of(value at address dptr) = address of(6422300) = address of(ptr) = &ptr
     *&dptr:    6422296     value at address(adress of dptr) = value at address(6422292) = value of dptr
     **dptr:    10          value at address(value at address dptr) = value at address(6422300) = value at address(ptr)

    *& == &*
    **dptr == *ptr == var

//
//       /* &**dptr:    6422300
//        **&dptr:    6422300
//        *&*dptr:    6422300
//       *&*&dptr:    6422296
//       &*&*dptr:    6422296
//       &**&dptr:    6422296
//      &*&*&dptr:    6422292*/
//ctrl + shift + c -> selected comment
//ctrl + shift + x -> selected comment


