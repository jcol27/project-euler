#include <stdio.h>
/*
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Unique dividers are: {20,19,18,17,16,15,14,13,12,11}
For loop with no terminator increasing from 1, check if non divisible with modulo and early
termination with break.
*/

int main() {
    int divs[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    for (int i = 1;;i++) {
        int factor = 1;
        for (int j = 0; j < 10; j++) {
            if (i % divs[j] != 0) {
                factor = 0;
                break;
            }
        }
        if (factor == 1) {
            printf("Solution = %lli", i);
            break;
        }
    }

}