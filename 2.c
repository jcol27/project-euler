#include <stdio.h>
/* 
By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.

Simple while loop 
*/
int main() {
    int prev = 1;
    int curr = 2;
    int sum = 0;
    int temp;

    while (curr < 4000000) {
        if (curr % 2 == 0) {
            sum += curr;
        }
        temp = prev;
        prev = curr;
        curr += temp;
    }

    printf("sum = %d", sum);
}