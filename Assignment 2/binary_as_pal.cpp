#include <iostream>
using namespace std;

long long findPalindrome(int input) {
    if (input == 1){
        return 1;
    }

    int len = 1;
    int count = 0;

    while (true) {
        int num_pal = 1 << ((len - 1) / 2);
        if (count + num_pal >= input) {
            break;
        }
        count += num_pal;
        len++;
    }

    int offset = input - count - 1;
    
    long long fHalf = (1LL << ((len - 1) / 2)) | offset;
    
    long long res = fHalf;
    
    int m_bits = len / 2;
    long long mirrorPart = fHalf;
    
    if (len % 2 != 0) {
        mirrorPart >>= 1; 
    }
    
    for (int i = 0; i < m_bits; i++) {
        res <<= 1;
        res |= (mirrorPart & 1);
        mirrorPart >>= 1;
    }

    return res;
}

int main() {
    int input = 9;
    // int input = 10;
    cout << findPalindrome(input) << endl;
    return 0;
}