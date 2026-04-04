#include <iostream>
using namespace std;

void manualSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            manualSwap(&arr[i], &arr[j]);
        }
    }
    manualSwap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int findMinXor(int arr[], int N) {
    if (N < 2) return 0;

    QuickSort(arr, 0, N - 1);

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
    int arr[] = {0, 2, 5, 7};
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = findMinXor(arr, N);

    cout << result << std::endl;

    return 0;
}