#include <stdio.h>
/*
What is the largest prime factor of the number 600851475143 ?

Simple loop for finding prime factors, works up from 2
*/
int main() {
    long long num = 600851475143;

    for (long long div = 2; div < num; div++) {
        while (div < num && num % div == 0) {
            num = num / div;
        }
    }
    printf("LPF = %lli\n", num);
}