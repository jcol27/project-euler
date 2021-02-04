#include <stdio.h>
#include <math.h>

// What is the value of the first triangle number to have over five hundred divisors?

int main() {
    long int sum = 0;
    int count;
    for (int i = 1; i < 1000000; i++) {
        sum = sum + i;
        count = 1;
        for (int j = 1; j < ceil(sum/2)+1; j++) {
            if (sum % j == 0) {
                count++;
            }
        }

        if (count > 500) {
            printf("Solution = %li", sum);
            break;
        }
    }
}