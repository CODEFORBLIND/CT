#include<stdio.h>
#include<stdbool.h>

void findVotingWinner(int arr[], int n){
    int min_idx;
    for(int i = 0; i<n; i++){
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
    int winner = arr[0];
    int maxCount = 0;

    int currentCan = arr[0];
    int currentCount = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == currentCan){
            currentCount++;
        } else {
            if(currentCount > maxCount){
                winner = currentCan;
                maxCount = currentCount;
            }
            currentCan = arr[i];
            currentCount = 1;
        }
    }
    printf("The winner is Candidate ID: %d with %d votes.\n", winner, maxCount);
}

// Method 2
//Counting sort used here
void findVotingWinnerOptimized(int arr[], int n) {
    int maxID = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxID){
        } maxID = arr[i];
    }

    int count[maxID + 1]; 
    for (int i = 0; i <= maxID; i++) count[i] = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int winner = 0;
    int maxCount = 0;
    for (int i = 0; i <= maxID; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            winner = i;
        }
    }
    printf("The winner is Candidate ID : %d with %d votes.\n", winner, maxCount);
}

int main(){
    // int arr[] = {1,5,5,2,7,5,6,6};
    int arr[] = {1,3,5,1,2,3,1,3,4,2,4,2,3,4,3,4,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    findVotingWinner(arr,n);
    findVotingWinnerOptimized(arr,n);
    return 0;
}