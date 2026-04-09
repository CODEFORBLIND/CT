#include <iostream>
#include <string>
using namespace std;

int getLength(const string& s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void genstrings(string arr[], int N, int counter, string currentStr) {
    if (counter == N) {
        cout << currentStr << " ";
        return;
    }
    
    int len = getLength(arr[counter]);
    
    for (int i = 0; i < len; i++) {
        genstrings(arr, N, counter + 1, currentStr + arr[counter][i]);
    }
}

int main() {
    string arr[] = {"ab", "cd"};
    int N = 2; 
    cout << "[ ";
    genstrings(arr, N, 0, "");
    cout << "]" << endl << endl;
    return 0;
}