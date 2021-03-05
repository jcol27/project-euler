#include <stdio.h>
#include <math.h>

/*
Considering quadratics of the form: n^2 + an + b where |a|<1000 and |b|<1000, find 
the product of the coefficients, a and b, for the quadratic expression that produces
the maximum number of primes for consecutive values of n, starting with n=0.

Brute force search with the following optimizations:
    1) prime numbers must be positive, so check n^2+an+b>0 before is_prime()
    2a) n^2 +an +b muist be prime for n=0, therefore b>1
    2b) since we only care about n_max, we can say (best_n+1)^2 + a*(best_n+1) + b 
    must be prime
    3) since for (a,b) to be better than the current best, (a,b,n_max+1) must be prime,
    thus we can rearrange for b to get a minimum value for b to start the loop from
    4) Given in the question is (a,b,n_max)=(-79,1601,79) so we can init best_n as 79
*/

/*
Function to find if a number is prime, simply
checks if a number is divisible by values other
than one and itself.
*/
int is_prime(int num) {
    int is_prime = 1; // 1 = prime, 0 = non-prime
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}

int main() {

    int best_a = 0;
    int best_b = 0;
    int best_n = 0;

    // Nested loops for a and b taking advantage of known relationships
    for (int a = -999; a < 1000; a++) {
        int b_start = (int) (fmax(1, -(pow(best_n,2) - a*best_n)));
        for (int b = b_start; b < 1000; b++) {
            int n = 0;

            // Check that (best_n+1)^2 + a*(best_n+1) + b is prime, since
            // otherwise (a,b) cannot be better than the current best
            int cond;
            if (pow(best_n+1,2) + a*(best_n+1) + b < 0) {
                cond = 0;
            }
            else {
                cond = is_prime(pow(best_n+1,2) + a*(best_n+1) + b);
            }

            // If (best_n+1)^2 + a*(best_n+1) + b is prime
            if (cond == 1) {
                // While n^2 + an + b > 0
                while (pow(n,2) + a*n + b > 0) {
                    int cond2;
                    if (pow(n,2) + a*n + b < 0) {
                        cond2 = 0;
                    }
                    else {
                        cond2 = is_prime(pow(n,2) + a*n + b);
                    }

                    // If n^2 + an + b is prime, go to next n
                    if (cond2 == 1) {
                        n = n + 1;
                    }
                    else {
                        break;
                    }
                }
                // Update best n
                n = n - 1;
                if (n > best_n) {
                    best_a = a;
                    best_b = b;
                    best_n = n;
                }
            }
        }
    }
    // Print solution
    printf("a = %d, b = %d, n = %d, a*b = %d", best_a, best_b, best_n, best_a*best_b);
}

