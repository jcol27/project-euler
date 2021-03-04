#include <stdio.h>
#include <math.h>
/* 
Find the sum of all the primes below two million.

Methods like the Sieve of Eratosthenes aren't ideal for this
sort of application as we need to calculate a large number of
primes, but really only want them sequentially.

This is a simple brute force algorithm.
*/

int main() { 
    long long int n = 2000000;
    long long int sum = 0;
    long int count = 0;
    long long int i,p;

    // Loop for numbers up to two million
    for (i = 2; i < n; i++) {
        int prime = 1;

        // Check if prime using basic dividers method up to sqrt(num)
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