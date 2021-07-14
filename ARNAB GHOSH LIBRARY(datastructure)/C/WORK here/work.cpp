#include<bits/stdc++.h>
using namespace std;


int rec(int num)
{
return (num) ? num%10 + rec(num/10):0;
}
main()
{
printf("%d",rec(4567));
}




// int main(void){
//     int arr[] = {1, 3, 8, 10};

//     for(int i:arr){
//         cout << (3*i + 4)%7 <<endl;
//     }

//     return 0;
// }

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     // write your code here
//     //cout << floor(log2(9));
//     // Arr[(2*i)+1]
//     // cout << 1.44 * log(7);

// //     Given n nodes2:

// // Minimum: ceil(log2(n+1))

// // Maximum: floor(1.44*log2(n+2)-.328)

// cout << floor(1.44*log2(7+2)-.328);
// cout << ceil(log2(7+1));
//     return 0;
// }

// void my_recursive_function(int *arr, int val, int idx, int len)
// {
// if(idx == len)
// {
// printf("-1");
// return ;
// }
// if(arr[idx] == val)
// {
// printf("%d",idx);
// return;
// }
// my_recursive_function(arr,val,idx+1,len);
// }
// int main()
// {
// int array[10] = {7, 6, 4, 3, 2, 1, 9, 5, 0, 8};
// int value = 2;
// int len = 10;
// my_recursive_function(array, value, 0, len);
// return 0;
// }