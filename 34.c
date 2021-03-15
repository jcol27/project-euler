#include <stdio.h>
#include <math.h>

/*
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: As 1! = 1 and 2! = 2 are not sums they are not included.

Digits  Max Sum of Factorials of Digits
1       362880
2       725760
3       1088640
4       1451520
5       1814400
6       2177280
7       2540160
8       2903040    

Therefore, the maximum number possible is less than 2903040.
Simple brute force loop. 
*/

int main() {
    int factorials[10] = {1,1,1,1,1,1,1,1,1,1};
    int sum, temp, digit;
    int total = 0;
    
    // Cache the factorials for efficiency
    for (int i = 9; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            factorials[i] = factorials[i]*j;
        }
    }

    // Loop over all numbers less than 9!*8
    for (int i = 3; i < 2903040; i++) {
        sum = 0;
        temp = i;

        // Loop to get all digits of the num
        while (temp > 0) {
            digit = temp % 10;
            sum += factorials[digit];
            temp /= 10;
        }

        // Update total
        if (sum == i) {
            total += sum;
        }
    }

    // Print solution
    printf("Total = %d\n", total);
}