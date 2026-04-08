#include<bits/stdc++.h>
using namespace std;

int findsecondmax(int arr[], int n){
    int max = arr[0];
    int secmax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > arr[i+1]){
            secmax = max;
            max = arr[i];
        } else if(arr[i] > secmax && arr[i] != max){
            secmax = arr[i];
        }
    }

    return (secmax == INT_MIN) ? -1 : secmax;


}

int main(){
    // int arr[] = {2, 5, 1, 6, 3};
    int arr[] = {5, 5, 5, 5, 5};
    int n = sizeof(arr)/ sizeof(int);
    int ret = findsecondmax(arr, n);
    cout << "Second max is: " << ret << endl;
return 0;
}