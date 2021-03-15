#include <stdio.h>
#include <math.h>

/*
The number 3797 has an interesting property. Being prime itself, it 
is possible to continuously remove digits from left to right, and 
remain prime at each stage: 3797, 797, 97, and 7. Similarly we can 
work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable 
from left to right and right to left.

Brute force with the following optimizations:
1) numbers that are truncatable primes must have prime first and
last digits


*/

/*
Function to find if a number is prime, simply
checks if a number is divisible by values other
than one and itself.
*/
int is_prime(int num) {
    int is_prime = 1; // 1 = prime, 0 = non-prime
    if (num == 0 || num == 1) {
        return 0;
    }

    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}

int main() {
    int count = 0;
    int num = 10;
    int truncatable = 0;
    int sum = 0;
    int len;

    // We know there are only 11, so while loop is most efficient
    while (count < 11) {
        len = floor(log10(abs(num))) + 1;

        // Prechecking num is valid
        int rem = num % 10;
        if (rem == 2 || rem == 3 || rem == 5 || rem == 7) {
            int msd = floor(num/pow(10,len-1));
            if (msd == 2 || msd == 3 || msd == 5 || msd == 7) {

                // Check that num is a truncatable prime
                truncatable = 1;
                // Loop going left to right
                for (int i = 0; i < len; i++) {
                    if (!is_prime(num % (int) (pow(10, len-i)))) {
                        truncatable = 0;
                    }
                }

                // Loop going right to left
                for (int j = len - 1; j >= 0; j--) {
                    if (!is_prime(floor(num/pow(10,j)))) {
                        truncatable = 0;
                    }
                }

                // Update sum and count
                if (truncatable) {
                    sum += num;
                    count++;
                }
            }
        }
        num++;
    }
    printf("Solution = %d", sum);
}