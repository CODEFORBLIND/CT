// MERGE SORT -> NlogN
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int s, int m, int e)
{
    int i  = s;
    int j = m+1;
    int temp[e];
    int r = 0;

    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            temp[r] = arr[i];
            i++;
            r++;
        }else{
            temp[r] = arr[j];
            j++;
            r++;
        }
    }

    while(i<=m){
        temp[r] = arr[i];
        r++;
        i++;
    }

    while(j<=e){
        temp[r] = arr[j];
        j++;
        r++;
    }


    for(int i = 0; i < r; i++){
        arr[s+i]= temp[i];
   }
    
}

void divide(int arr[], int s, int e){

    int m = (s+e)/2;

    if(s<e){
    divide(arr, s,m);
    divide(arr,m+1,e);
    merge(arr, s, m, e);
    }

}

int main(){
    int arr[] = {2,1,4,5,22,43,5,6};
    int n = sizeof(arr)/sizeof(int);
    divide(arr,0,n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
return 0;
}
