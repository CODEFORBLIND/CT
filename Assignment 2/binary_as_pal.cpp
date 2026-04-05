#include <iostream>
using namespace std;

long long reverseBits(long long n, int len) {
    long long rev = 0;
    for (int i = 0; i < len; i++) {
        if (n & (1LL << i)) {
            rev |= (1LL << (len - 1 - i));
        }
    }
    return rev;
}

/**
 * Function to find the Ath Binary Palindrome.
 */
long long findAthPalindrome(int A) {
    if (A == 1) return 1; // 1st is "1"

    int len = 1;
    int count = 0;

    // Step 1: Find the bit-length of the Ath palindrome
    while (true) {
        int num_palindromes = 1 << ((len - 1) / 2);
        if (count + num_palindromes >= A) {
            break;
        }
        count += num_palindromes;
        len++;
    }

    // Step 2: Find the specific number within that length group
    int offset = A - count - 1;
    
    // The first half starts with '1' followed by the binary of 'offset'
    long long firstHalf = (1LL << ((len - 1) / 2)) | offset;
    
    // Step 3: Construct the full palindrome
    long long result = firstHalf;
    
    // If length is odd (e.g., 5), we ignore the middle bit when mirroring
    // If length is even (e.g., 4), we mirror everything
    int bitsToMirror = len / 2;
    long long mirrorPart = firstHalf;
    
    if (len % 2 != 0) {
        mirrorPart >>= 1; // Drop middle bit for odd lengths
    }
    
    // Shift the first half to the left and attach the mirrored part
    for (int i = 0; i < bitsToMirror; i++) {
        result <<= 1;
        result |= (mirrorPart & 1);
        mirrorPart >>= 1;
    }

    return result;
}

int main() {
    int A = 9; 
    // Palindromes: 1, 3, 5, 7, 9, 15, 17, 21, 27...
    // 9th should be 27 (11011 in binary)
    
    cout << findAthPalindrome(A) << endl;
    
    return 0;
}