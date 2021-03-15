#include <stdio.h>
#include <math.h>

/*
The decimal number, 585 = 1001001001_2 (binary), is palindromic 
in both bases. Find the sum of all numbers, less than one million, 
which are palindromic in base 10 and base 2. Note: the palindromic 
number, in either base, may not include leading zeros.


*/

/*
Evaluates whether a number (in any base) is palindromic
*/
int is_palindrome(int n) {
    int digit;
    int len = floor(log10(abs(n))) + 1;
    int digits[100] = {0};
    int j = 0;
    int palindrome = 1;
    int temp = n;

    // Loop to get all digits of the num
    while (temp > 0) {
        digit = temp % 10;
        digits[len-j-1] = digit;
        temp /= 10;
        j++;
    }

    for (int i = 0; i < len/2; i++) {
        if (digits[i] != digits[len-i-1]) {
            palindrome = 0;
            break;
        }
    }

    return palindrome;
}

/*
Converts a base ten number to binary
*/
unsigned long long int to_binary(unsigned long long int n) {
   return (n == 0 || n == 1 ? n : ((n % 2) + 10 * to_binary(n / 2)));
}

int main() {
    int sum = 0;
    for (unsigned long long int i = 0; i < 1000000; i++) {
        // Check base 10 first since it is shorter
        if (is_palindrome(i)) {
            if (is_palindrome(to_binary(i))) {
                printf("%d, %d\n", i, to_binary(i));
                sum += i;
            }
        }
    }

    printf("Solution = %d\n", sum);
}