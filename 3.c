#include <stdio.h>
// What is the largest prime factor of the number 600851475143 ?
int main() {
    long long num = 600851475143;

    for (long long div = 2; div < num; div++) {
        if (div > num) {
            break;
        }
        
        while (div < num && num % div == 0) {
            num = num / div;
            printf("num = %lli\n", num);
        }
    }
    printf("LPF = %lli\n", num);
}