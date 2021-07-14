#include<stdio.h>
#include"printIO.h"
int main(void){  
    OpenIO(fopen("1st.c", "a"));
    int a;
    scanf("%d", &a);
    printf("%d", a);
    return 0;
}
//https://code.visualstudio.com/docs/editor/codebasics
//gcc -o 1st.c 1st
// enable Autosave from File > Auto Save toggle
//multi-cursor using Alt+Click
//Multi-cursor modifier Ctrl+Click
//Find and Replace Ctrl+F

