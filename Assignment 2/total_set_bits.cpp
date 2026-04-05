#include<iostream>
using namespace std;

long long MOD = 1000000007;

int calcLargest2Power(int n) {
    int y = 0;
    while ((1 << (y + 1)) <= n) {
        y++;
    }
    return y;
}

int setBitCount(int num) {
    if (num == 0){
        return 0;
    } 

    int x = calcLargest2Power(num);
    
    long long bitsTillPower = (long long)x * (1LL << (x - 1));
    
    long long msb = (num - (1LL << x) + 1);
    
    long long total = (bitsTillPower % MOD + msb % MOD + setBitCount(num - (1LL << x)) % MOD) % MOD;
    
    return (int)total;
}

int main(){
    int count = setBitCount(11);
    cout<< "Total set bits are: "<<count;

    return 0;
}