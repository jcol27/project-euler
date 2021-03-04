#include <stdio.h>
#include <math.h>

/*
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

First it is necessary to define reasonable bounds on our search. The smallest number of n digits
that can be written as the sum of the fifth powers of its digits is obviously n*1^1 + (n-1)*0^5 = n. The 
largest number of n digits that can be written as the sum of the fifth powers of its digits 
is obviously n*9^5. This gives:
    n   n*9^5       practical
    1   59049       9
    2   118098      99
    3   177147      999
    4   236196      9999
    5   295245      99999
    6   354294      354294
    7   413343      n/a
*/

int main() {
    // Find n_max
    int n_max = 1; 
    while (n_max*pow(9,5) > pow(10,n_max)) {
        n_max += 1;
    }
    n_max += 1;

    int sum = -1; // To ignore 1 = 1^5
    for (int i = 1; i < n_max + 1; i++) {
        for (int j = pow(10, i-1); j < (int) fmin(pow(10, i), i*pow(9,5)); j++) {
            // Convert j to array of digits
            int digits[i];
            int k = j;
            int count = 0;

            while (k != 0) {
                digits[count] = k % 10;
                k /= 10;
                count += 1;
            }

            // Find sum of digits to the power of 5
            int sum_digits = 0;
            for (int a = 0; a < count; a++) {
                sum_digits += pow(digits[a],5);
            }

            if (sum_digits == j) {
                sum += j;
            }
        }
    }

    printf("sum = %d", sum);
}