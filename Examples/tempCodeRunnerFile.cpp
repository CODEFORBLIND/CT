#include<bits/stdc++.h>
// using namespace std;

// int minplatforms(int arr[], int dep[], int size){
//     int plt = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i] < dep[i]){
//             if(arr[i+1] >= dep[i]){
//             } else if(arr[i+1] < dep[i]){
//                 plt++;
//             } 
//         }
//     }
//     return plt;
// }

// int main(){
//     int arr[] = {200, 259, 339, 359, 559};
//     int dep[] = {300, 340, 400, 600, 715};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int number = minplatforms(arr, dep, size);
//     cout << "Min number of platforms: " << number << endl;
//     return 0;
// }