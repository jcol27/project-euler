#include <stdio.h>
#include <math.h>
/* 
Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.

Two simple for loops to calculate the two values
*/
int main() {
    int n = 100;
    // Sum of squares
    long long int sum1 = 0;
    for (int i = 1; i < n+1; i++) {
        sum1 += pow(i,2);
    }

    // Square of sum
    long long int sum2 = 0;
    for (int i = 1; i < n+1; i++) {
        sum2 += i;
    }
    sum2 = pow(sum2,2);

    long long int diff = sum2 - sum1;
    printf("Solution = %lli", diff);
}