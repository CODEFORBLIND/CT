#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Required for 'bool', 'true', 'false'

bool isSubstringPresent(char str[], char sub[]) {
    int n = strlen(str);
    int m = strlen(sub);

    // If substring is longer than main string, it can't be present
    if (m > n) return false;

    // Loop through the main string
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check for pattern match starting at index i
        for (j = 0; j < m; j++) {
            if (str[i + j] != sub[j]) {
                break; // Mismatch found, move to next i
            }
        }

        // If inner loop finished (j reached m), we found the match
        if (j == m) {
            return true;
        }
    }

    return false; // No match found after scanning entire string
}

int main() {
    char mainText[] = "Algorithm and Data Structures";
    char pattern[] = "Data";

    printf("Main String: %s\n", mainText);
    printf("Searching for: %s\n", pattern);

    if (isSubstringPresent(mainText, pattern)) {
        printf("Result: True (Substring Found!)\n");
    } else {
        printf("Result: False (Substring Not Found.)\n");
    }

    return 0;
}