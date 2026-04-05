#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++){
        right[j] = arr[mid + 1 + j];
    } 

    int i = 0; 
    int j = 0; 
    int k = low; 

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}


void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


int findMinXor(int arr[], int N) {
    if (N < 2) return 0;

    MergeSort(arr, 0, N - 1);

    int minXor = arr[0] ^ arr[1];
    for (int i = 1; i < N - 1; i++) {
        int currentXor = arr[i] ^ arr[i + 1];
        if (currentXor < minXor) {
            minXor = currentXor;
        }
    }
    return minXor;
}

int main() {
    int arr[] = {0, 5, 2, 7};
    // int arr[] = {6, 9, 12, 20};
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = findMinXor(arr, N);

    cout << result << endl;

    return 0;
}