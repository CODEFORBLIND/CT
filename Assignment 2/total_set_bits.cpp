#include<iostream>
using namespace std;

long long modulo = 1000000007;

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
    
    long long total = (bitsTillPower % modulo + msb % modulo + setBitCount(num - (1LL << x)) % modulo) % modulo;
    
    return (int)total;
}

int main(){
    // int count = setBitCount(11);
    int count = setBitCount(21);
    cout<< "Total set bits are: "<<count;

    return 0;
}