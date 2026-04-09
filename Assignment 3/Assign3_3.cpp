#include <iostream>
using namespace std;

void Sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void combSum(int A[], int size, int target, int index, int currentArr[], int currentLen, int currentSum) {
    if (currentSum == target) {
        cout << "[";
        for (int i = 0; i < currentLen; i++) {
            cout << currentArr[i] << (i == currentLen - 1 ? "" : ", ");
        }
        cout << "]" << endl;
        return;
    }

    for (int i = index; i < size; i++) {
        if (i > index && A[i] == A[i - 1]) continue;
        
        if (currentSum + A[i] > target) break;

        currentArr[currentLen] = A[i];
        
        combSum(A, size, target, i + 1, currentArr, currentLen + 1, currentSum + A[i]);
    }
}

int main() {
    int A[] = {10, 1, 2, 7, 6, 1, 5};
    int size = 7;
    int target = 8;
    
    Sort(A, size);
    
    int currentArr[20]; 
    combSum(A, size, target, 0, currentArr, 0, 0);
    cout << endl;
}