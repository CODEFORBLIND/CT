#include <iostream>
#include <vector>
using namespace std;

void sort012(int arr[], int n) {
    int first = 0;
    int last = n-1;
    int counter = 0;
    while(counter <= last){
        if(arr[counter] == 0){
            swap(arr[first], arr[counter]);
            first++;
            counter++;
        } else if(arr[counter] == 2){
            swap(arr[counter], arr[last]);
            last--;
        } else{
            counter++;
        }
    }
}

int main() {
    int arr[] = { 0, 1, 2, 0, 1, 2, 0, 0 ,0, 2, 1};
    int n = sizeof(arr)/ sizeof(int);
    
    sort012(arr, n); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}