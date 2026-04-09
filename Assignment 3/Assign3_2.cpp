#include <iostream>
using namespace std;

void comHelp(int n, int k, int start, int currArr[], int currLen) {
    if (currLen == k) {
        cout << "  [";
        for (int i = 0; i < k; i++) {
            cout << currArr[i] << (i == k - 1 ? "" : ",");
        }
        cout << "]" << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        currArr[currLen] = i; 
        comHelp(n, k, i + 1, currArr, currLen + 1); 
    }
}

int main() {
    int n = 4;
    int k = 2;
    int currArr[5]; 
    
    cout << "[" << endl;
    comHelp(n, k, 1, currArr, 0);
    cout << "]" << endl << endl;
}