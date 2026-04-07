#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int m, int s, int e){
    int i = s;
    int j = m+1;
    int r = 0;
    int temp[e];
    while (i <= m && j <= e)
    {
        if(arr[i] < arr[j]){
            temp[r] = arr[i];
            i++;
            r++;
        } else { 
            temp[r] = arr[j];
            j++;
            r++;
        }
    }
    while (i <= m)
    {
        temp[r] = arr[i];
        i++;
        r++;
    }
    while (j <= e)
    {
        temp[r] = arr[j];
        j++;
        r++;
    }
    for (int i = 0; i < r; i++)
    {
        arr[s+i] = temp[i];
    }

}

void divide(int arr[], int s, int e){
    int m = (s+e)/2;

    if(s < e) {
        divide(arr, s, m);
        divide(arr, m+1, e);
        merge(arr, m, s, e);
    }

}

int main(){
    int arr[] = {1,3,6,2,8,0};
    int n = sizeof(arr)/ sizeof(int);
    divide(arr,0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
return 0;
}