#include <stdio.h>
#include <math.h>
// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
// Which starting number, under one million, produces the longest chain?

int main() {
    int chain = 0;
    int max_chain = 0;
    long int max_chain_start = 0;
    for (long int i = 2; i < 1000000; i++) {
        long long int n = i;
        chain = 0;
        while (n != 1) {
            if ((n % 2) == 0) {
                n = n / 2;
            }
            else {
                n = 3*n + 1;
            }
            chain++;
        }
        if (chain > max_chain) {
            max_chain = chain;
            max_chain_start = i;
        }
    }
    printf("Solution start: %li, chain length: %li", max_chain_start, max_chain);
}