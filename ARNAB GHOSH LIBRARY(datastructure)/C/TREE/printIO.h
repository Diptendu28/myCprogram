#include<stdio.h>
void OpenIO(FILE *f){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fclose(f);
}
    
