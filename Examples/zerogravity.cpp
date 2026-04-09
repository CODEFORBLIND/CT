// #include<bits/stdc++.h>
// using namespace std;

// void zerosinend(int arr[], int n){
//     for (int i = n-1; i >= 0; i--)
//     {
//         if(arr[i] == 0){
//             for (int j = i; j < n-1; j++)
//             {
//                 arr[j] = arr[j+1];
//             }
//             arr[n-1] = 0;
//         }
//     }
// }

// int main(){
//     int arr[] = {1, 0, 3, 0, 2, 0, 0, 0, 4, 5, 9};
//     int n = sizeof(arr)/ sizeof(int);
//     zerosinend(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
    
// return 0;
// }


#include<bits/stdc++.h>
using namespace std;

void zerosinendOptimal(int arr[], int n){
    int nonZeroIndex = 0; 
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main(){
    int arr[] = {1, 0, 3, 0, 2, 0, 0, 0, 4, 5, 9};
    int n = sizeof(arr) / sizeof(int);
    
    zerosinendOptimal(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}