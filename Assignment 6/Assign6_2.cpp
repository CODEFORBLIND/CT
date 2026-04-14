#include <bits/stdc++.h>
using namespace std;

void longest_subseq(int stock_price[], int n){
    int max = 0;
    int init;
    int curr_size = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){
        curr_size++;
        if (stock_price[i]< stock_price[i+1]){
            curr++;
        }else{
            if (curr_size> max){
                max = curr_size;
                init = curr-curr_size+1;
                curr_size = 0;
                curr++;
            }
        }
    }
    cout<< "Longest Subarray Size: " << max << endl;
    for (int i = init; i< init+max; i++){
        cout<< stock_price[i] << " ";
    }
}

int main() {
    int stock_price[] = {2,3,5,2,6,7,9,1,5,8};
    int n = sizeof(stock_price)/sizeof(int);

    longest_subseq(stock_price, n);
    return 0;
}