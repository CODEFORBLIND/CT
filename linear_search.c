#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        // Check if current element matches the target
        if (arr[i] == target) {
            return i; // Return the index immediately
        }
    }
    return -1; // If loop finishes, target is not in array
}

int main() {
    int myData[] = {12, 45, 67, 8, 90, 21};
    int size = sizeof(myData) / sizeof(myData[0]);
    int target;

    printf("Array: 12, 45, 67, 8, 90, 21\n");
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int result = linearSearch(myData, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}