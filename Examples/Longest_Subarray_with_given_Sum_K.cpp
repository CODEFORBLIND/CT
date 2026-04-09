#include <iostream>
using namespace std;

int longestsubarray(int arr[], int n, int k){
    int maxlen = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int sum = 0;
            for (int k = i ; k<= j; k++){
                sum +=arr[k];
            }
            if (sum == k){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int size = sizeof(arr)/sizeof(int);
    int k = 15;
    cout<< longestsubarray(arr,size,k);
    return 0;
}