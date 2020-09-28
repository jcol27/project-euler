#include <stdio.h>
#include <math.h>
// There exists exactly one Pythagorean triplet for which a + b + c = 1000, a < b < c, a^2 + b^2 = c^2
// Find the product abc.
int main() {
    for (int a = 0; a < 1000; a++) {
        for (int b = a + 1; b < 1000; b++) {
            for (int c = b + 1; c < 1000; c++) {
                if (pow(a,2) + pow(b,2) == pow(c,2) && a+b+c == 1000) {
                    printf("a = %i, b = %i, c = %i\n", a,b,c);
                    printf("product abc = %i", a*b*c);
                    break;
                }
            }
        }
    }
}