#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 
Let d(n) be defined as the sum of proper divisors of 
n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b 
are an amicable pair and each of a and b are called 
amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.
*/

int compare( const void* a, const void* b)
{
   int int_a = * ( (int*) a );
   int int_b = * ( (int*) b );

   // An easy expression for comparing
   return (int_a > int_b) - (int_a < int_b);
}


int main() {
    // Create array of divisor sums
    int sums[10000];
    for (int i = 1; i <= 10000; i++) {
        int sum_divisors = 0;
        for (int j = 1; j < ceil(i/2) + 2; j++) {
            if (i % j == 0) {
                sum_divisors = sum_divisors + j;
            }
        }
        sums[i] = sum_divisors;
    }

    // Check for amicable pairs
    int sum_amicables = 0;
    int amicables[10000];
    int pos = 0;
    for (int i = 1; i <= 10000; i++) {
        for (int j = i+1; j < 10000; j++) {
            if (sums[i] == j && sums[j] == i) {
                amicables[pos] = i;
                amicables[pos + 1] = j;
                pos = pos + 2;
            }
        }
    }

    // Sort amicables (makes processing duplicates much easier)
    qsort(amicables, 10000, sizeof(int), compare);

    // Remove duplicates
    for (int i = 0; i < 10000; i++) {
        int last_unique = 0;
        if (amicables[i] > last_unique) {
            sum_amicables = sum_amicables + amicables[i];
            last_unique = amicables[i];
        }
    }

    printf("Sum of amicable numbers = %d", sum_amicables);
}
