#include <iostream>
using namespace std;

int countTrailingZeroes(int A) {

    if (A == 0) {
        return 0;
    }

    int count = 0;
    while ((A & 1) == 0) {
        count++;      
        A = A >> 1;   
    }

    return count;
}

int main() {
    int A = 18;
    // int A = 24;
    int result = countTrailingZeroes(A);
    cout << result << endl;
    return 0;
}