#include <stdio.h>
#include <math.h>
// Find the sum of all the primes below two million.
int main() { 
    long long int n = 2000000;
    long long int sum = 0;
    long int count = 0;
    long long int i,p;
    for (i = 2; i < n; i++) {
        int prime = 1;
        for (p = 2; p < ceil(sqrt(n))+2; p++) {
            if (i != p && i % p == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            sum += i;
        }
    }
    printf("Solution = %lli", sum);
}