#include <stdio.h>
/* 
What is the 10 001st prime number?


Uses the sieve of Eratosthenes method (not the fastest, but fine for this) O(N log log N)
Large array inefficient space-wise but its only ~800kb.
See: https://www.wikiwand.com/en/Generation_of_primes
*/
int main() {
    int goal = 10001;
    int n = 200000;
    int possibles[200000] = {0};

    for (int p = 2; p < n; p++) {
        for (int i = 0; i < n; i++) {
            if (i/2 + 1 > p && i % p == 0) {
                possibles[i] = 1;
            }
        }
    }

    int count = 1;
    for (int j = 2; j < n; j++) {
        if (possibles[j] == 0) {
            if (count == goal) {
                printf("Solution = %i", j);
                break;
            }
            count++;
        }
    }
}