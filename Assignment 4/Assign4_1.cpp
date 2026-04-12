#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

    bool check(string s1, string s2) {
        unordered_map<string, bool> memo;
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        // Pruning: Scrambled strings must have the same character counts
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) return memo[key] = false;

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            if (check(s1.substr(0, i), s2.substr(0, i)) && 
                check(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            if (check(s1.substr(0, i), s2.substr(n - i)) && 
                check(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }


int main() {
    string A = "great", B = "rgtae";
    // string A = "greate", B = "rgtae";
    cout << "Is Scramble: " << check(A, B) << endl;
    return 0;
}