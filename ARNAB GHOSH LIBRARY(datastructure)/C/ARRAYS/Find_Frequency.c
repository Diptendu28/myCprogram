#include<stdio.h>
#define visited -1
void printFreq(int arr[], int freq[], int len){ // print the frequency of each element

    for(int i = 0; i < len; i++){
        if(freq[i] != visited){
            printf("The elements %d occurs for %d times.\n",arr[i],freq[i]);
        }
    }
}

void findFreq(int* arr, int len){ // find the frequency of each element
    int freq[100], occur = 1;
    for(int i = 0; i < len; i++){ // select each element
        occur = 1;
        for(int j = i + 1; j < len; j++){ // compare the selected element
            if(arr[i] == arr[j]){
                occur++; // count the frequency
                freq[j] = visited; // assign the duplicates with -1
            }
        }
        if(freq[i] != visited){ // if the value is -1 then count performed but not assiged
            freq[i] = occur;
        }
    }
    printFreq(arr, freq, len);
}



int main(void) {
    int arr[100];
    int size;
    printf("Enter the size of the array(must be <=100): ");
    scanf("%d", &size); // declare the size of the array
    printf("Enter elements in the array:\n");
    for(int i = 0; i < size; i++) { // add elements to the array
        scanf("%d", &arr[i]);
    }
    findFreq(arr, size);
    return 0;
}

// INPUT: 15 - 1 2 3 1 5 2 9 5 1 2 2 4 3 3 0
/*
OUTPUT:
The elements 1 occurs for 3 times.
The elements 2 occurs for 4 times.
The elements 3 occurs for 3 times.
The elements 5 occurs for 2 times.
The elements 9 occurs for 1 times.
The elements 4 occurs for 1 times.
The elements 0 occurs for 1 times.
*/
