#include<bits/stdc++.h>
using namespace std;

// 1 2 3 4 5
// 5 1 2 3 4 
// 4 5 1 2 3

void rotateright(int arr[], int n, int counter){
    int count  = 0;
    while(count < counter){
        int temp = arr[n-1];
        for (int i = n-1; i >= 0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
        count++;
    }

    
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int counter = 2;
    rotateright(arr, n, counter);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
return 0;
}