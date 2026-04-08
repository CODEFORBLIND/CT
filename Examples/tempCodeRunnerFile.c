#include <stdio.h>
// Method 1
void selectionSort(int arr[], int n){
    int min_idx;
    for(int i = 0; i<n; i++){
        min_idx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


// Method 2
// Radix Sort used here
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
        max = arr[i];
    }
    return max;
}

void SortArr(int arr[], int n, int expo) {
    int finalarr[n]; 
    int count[10] = {0};

    for (int i = 0; i < n; i++){
        count[(arr[i] / expo) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        finalarr[count[(arr[i] / expo) % 10] - 1] = arr[i];
        count[(arr[i] / expo) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = finalarr[i];
}


void radixSort(int arr[], int n) {
    int maxx = findMax(arr, n); 
    for (int expo = 1; maxx / expo > 0; expo *= 10){
        SortArr(arr, n, expo);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 5, 7, 0, 2, 4, 22, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr,n);
    printArray(arr,n);
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}