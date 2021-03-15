#include <stdio.h>
#include <math.h>

/*
An irrational decimal fraction is created by concatenating the 
positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the 
value of the following expression:
d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000

While loop until d = 1000000 incrementing through the positive 
integers and counting the digits. Only actually evaluate the 
digit if it is one of interest for efficiency.
*/


/*
Function to find the nth digit of an integer
n=0 means the least significant digit
*/
int nthdigit(int x, int n)
{
    static int powersof10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    return ((x / powersof10[n]) % 10);
}

int main() {
    int d = 1;
    int num = 1;
    int len;
    int nums[6] = {0};
    int sol = 1;

    // While loop until d = 1000000
    while (d < 1000000) {
        // Get length of num
        len = floor(log10(abs(num))) + 1;

        // Loop over digits of num
        for (int i = 0; i < len; i++) {
            // Loop over d values of interest
            for (int j = 0; j < 6; j++) {
                // If d value is of interest
                if (d == pow(10,j)) {
                    // Update solution
                    sol = sol * nthdigit(num, len - i - 1);
                }
            }
            // Increment d
            d++;
        }
        // Increment num
        num++;
    }

    // Print solution
    printf("Solution = %d", sol);
}