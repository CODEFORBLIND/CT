#include<stdio.h>
#include<stdbool.h>

// Method 1

bool findDuplicateElem(int arr[], int n){
    int min_idx;
    for(int i = 0; i<n; i++) {
        min_idx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        if(arr[i] == arr[i+1]){
            return true;
        }
    }
    return false;

}

// Method 2
//Heap sort used here
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

bool findDuplicateElemOptimized(int arr[], int n) {
    heapSort(arr, n);
    for (int i = 0; i < n - 1; i++) { 
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}



int main(){
    int arr[] = {1,5,5,2,7,5,6};
    // int arr[] = {1,9,5,2,7,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    findDuplicateElem(arr,n);
    if (findDuplicateElem(arr,n)){
        printf("Repeated Element Found!\n");
    } else{
        printf("No Repeated Elements found!\n");
    }
    findDuplicateElemOptimized(arr,n);
    if (findDuplicateElemOptimized(arr,n)){
        printf("Repeated Element Found!\n");
    } else{
        printf("No Repeated Elements found!\n");
    }
    return 0;
}