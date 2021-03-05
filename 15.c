#include <stdio.h>
#include <stdint.h>

/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the 
right and down, there are exactly 6 routes to the bottom right corner. How many 
such routes are there through a 20×20 grid?

This can be formulated as a permutations problem, where we are trying to find all
unique orderings of the exactly 40 necessary moves (20 rights and 20 downs) where
the rights and downs are interchangeable.
From permutations theory, if you want to find permutations of N elements 
where there are two types of elements, R(ight) and D(own), and A is the number
of times R is repeated and B is the number of times D is repeated, then the number 
of permutations is N!/(A!*B!)
Therefore, ans = 40!/(20!*20!)
*/

int main() {
    uint64_t product = 1;

    // Simple for loop to solve 40!/(20!*20!)
    for (uint64_t i = 1; i < 41; i++) {
        product = product * i;
        if (i % 2 == 0) {
            product = product / (i/2);
            product = product / (i/2);
        }
    }
    printf("Solution = %llu\n", product);
}