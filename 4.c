#include <stdio.h>
#include <stdlib.h>
/*
Find the largest palindrome made from the product of two 3-digit numbers.

Brute force loop for products of two three digit numbers. Check for 
palindrome for two cases (even/odd number of digits) by converting to 
string. 
*/
int main() {
    // Loop through three digit numbers
    long int largest = 0;
    int num1, num2;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            long int num = i*j;
            char snum[10];
            int palindrome = 1;
            itoa(num, snum, 10);

            // If string has even number of chars
            if (strlen(snum) % 2 == 0) {
                for (int k = 0; k < strlen(snum)/2; k++) {
                    if (snum[k] != snum[strlen(snum)-k-1]) {
                        palindrome = 0;
                        break;
                    }
                }
            }   
            // If string has odd number of chars
            else {
                for (int k = 0; k < (strlen(snum)-1)/2; k++) {
                    if (snum[k] != snum[strlen(snum)-k-1]) {
                        palindrome = 0;
                        break;
                    }
                }

            }
            // Store current largest
            if (palindrome == 1 && num > largest) {
                largest = num;
                num1 = i;
                num2 = j;
            }
        }
    }

    // Print
    printf("Largest palindrome = %lli (%i x %i)\n", largest, num1, num2);
}