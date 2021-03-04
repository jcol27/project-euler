#include <stdio.h>
#include <math.h>

/*
Starting with the number 1 and moving to the right in a clockwise direction 
a 1001 by 1001 spiral can be formed. What is the sum of the numbers on the
diagonals?

Write out beginning of spiral and fit parabolas to diagonal series by solving
simultaneous equations:
up + left diagonal: 1, 7, 21, 43, 73, 111
    pattern: a_n = 4n^2+2n+1
up + right diagonal: 1, 9, 25, 49, 81, 121
    pattern: a_n = 4n^2+4n+1
down + left diagonal: 1, 5, 17, 37, 65, 101
    pattern: a_n = 4n^2+1
down + right diagonal: 1, 3, 13, 31, 57, 91
    pattern: a_n = 4n^2-2n+1
*/

#define spiral_size 1001

int main() {
    int sum = 1;
    int sum_up_left = 0;
    int sum_up_right = 0;
    int sum_down_left = 0;
    int sum_down_right= 0;

    for (int i = 1; i < (spiral_size+1)/2; i++) {
        sum_up_left = sum_up_left + 4*pow(i,2) + 2*i + 1;
        sum_up_right = sum_up_right + 4*pow(i,2) + 4*i + 1;
        sum_down_left = sum_down_left + 4*pow(i,2) + 1;
        sum_down_right = sum_down_right + 4*pow(i,2) - 2*i + 1;
    }
    sum = sum + sum_up_left + sum_up_right + sum_down_left + sum_down_right;

    printf("Sum = %d", sum);
}
