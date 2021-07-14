#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void){
    char str[20];
    int len, mid, flag = 0;
    printf("Enter the string: ");
    scanf("%s",&str);
    len = strlen(str);
    if(len%2!=0){ // odd length
        mid = (int)ceil((double)len/2);
        mid--;
        for(int i = mid-1, j = mid+1; i>=0, j<len; i--, j++){
            if(str[i]!=str[j]){
                flag = 1;
            }
        }
    }
    else{ // even length
        mid = len/2;
        mid--;
        for(int i = mid, j = mid+1; i>=0, j<len; i--, j++){
            if(str[i]!=str[j]){
                flag = 1;
            }
        }
    }
    if(flag){
        printf("Not Palindrom");
    }
    else{
        printf("Palindrom");
    }
    return 0;
}