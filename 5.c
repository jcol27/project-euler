#include <stdio.h>
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int main() {
    int divs[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    long long int max = 20*19*18*17*16*15*14;
    max = max*13*12*11*10*9*8*7*6*5*4*3*2;
    for (long long int i = 1; i < max; i++) {
        int factor  = 1;
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