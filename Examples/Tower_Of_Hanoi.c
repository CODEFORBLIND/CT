#include <stdio.h>
#include <math.h>

// Global variable to count total moves
int moveCount = 0;

// Recursive function for Tower of Hanoi
void solveHanoi(int n, char source, char dest, char aux) {
    if (n == 0) {
        return;
    }
    
    // Step 1: Move n-1 disks from source to aux
    solveHanoi(n - 1, source, aux, dest);
    
    // Step 2: Move the actual disk
    printf("Move disk %d from %c to %c\n", n, source, dest); 
    moveCount++;
    
    // Step 3: Move n-1 disks from aux to dest
    solveHanoi(n - 1, aux, dest, source);
}

int main() {
    int n = 4; // Number of disks
    
    printf("Solving Tower of Hanoi for n = %d disks...\n", n);
    solveHanoi(n, 'A', 'C', 'B');
    
    printf("\nTotal moves performed: %d\n", moveCount);
    printf("Theoretical moves (2^n - 1): %.0f\n", pow(2, n) - 1);
    
    return 0;
}