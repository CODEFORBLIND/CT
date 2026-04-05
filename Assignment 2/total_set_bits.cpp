#include <iostream>
using namespace std;

/**
 * Function to count total set bits from 1 to A.
 * Uses column-wise pattern recognition for O(log A) complexity.
 */
int countTotalSetBits(int A) {
    long long totalCount = 0;
    long long mod = 1000000007;
    long long n = A;
    
    // We iterate through each bit position (1, 2, 4, 8...)
    // There are about 31 bits in 10^9.
    for (int i = 0; (1LL << i) <= n; i++) {
        
        // Total numbers from 0 to A is (n + 1)
        long long totalNumbers = n + 1;
        
        // The pattern of 0s and 1s repeats every 'blockSize'
        long long blockSize = 1LL << (i + 1);
        
        // Number of full blocks of 0s and 1s
        long long fullBlocks = totalNumbers / blockSize;
        
        // Each full block contains (blockSize / 2) ones
        long long onesInFullBlocks = fullBlocks * (1LL << i);
        
        // Handle the remaining numbers that don't form a full block
        long long remaining = totalNumbers % blockSize;
        long long onesInRemaining = 0;
        
        // If remaining numbers reach into the 'ones' part of the block
        if (remaining > (1LL << i)) {
            onesInRemaining = remaining - (1LL << i);
        }
        
        totalCount = (totalCount + onesInFullBlocks + onesInRemaining) % mod;
    }
    
    return (int)totalCount;
}

int main() {
    int A = 3; 
    // Numbers 1 (01), 2 (10), 3 (11). Total bits: 1 + 1 + 2 = 4.
    
    cout << "Total set bits: " << countTotalSetBits(A) << endl;
    
    return 0;
}