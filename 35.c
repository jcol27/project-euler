#include <stdio.h>
#include <math.h>

/*
The number, 197, is called a circular prime because all 
rotations of the digits: 197, 971, and 719, are themselves 
prime. How many circular primes are there below one million?

Solved by brute force. Hard to see any real optimizations.
Maybe generating primes under one million first, then
checking for cycles is possible, but may even be slower.

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
    int n = 1000000;
    int temp, digit, len, newprime;
    int cprimes = 0;
    int j = 0;

    for (int p = 2; p < n; p++) {
        if (is_prime(p)) {
            temp = p;
            len = floor(log10(abs(p))) + 1;
            j = 0;
            int circular = 1;
            int digits[6] = {0};
            for (int i = 0; i < 7; i++) {
                digits[i] = -1;
            }    
            while (temp > 0) {
                digit = temp % 10;
                digits[len-j-1] = digit;
                temp /= 10;
                j++;
            }
            for (int k = 1; k < len; k++) {
                newprime = 0;
                int count = 0;
                int pos = k+count;
                while (count < len) {
                    if (digits[pos] != -1) {
                        newprime += digits[pos]*pow(10,len-count-1);
                        count++;
                        pos++;
                    }
                    else {
                        pos = 0;
                    }
                }
                if (!(is_prime(newprime))) {
                    circular = 0;
                    break;
                }
            }
            if (circular == 1) {
                cprimes++;
            }
        }
    }

    printf("Solution = %d\n", cprimes);
}