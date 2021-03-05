#include <stdio.h>
/* 
What is the greatest product of four adjacent numbers in the same direction 
(up, down, left, right, or diagonally) in the 20×20 grid?

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

Optimized with the same product caching method used in 
problem eight.

*/

#define SIZE 20

int getInt(char grid[], int pos) {
    int a = grid[pos] - '0';
    int b = grid[pos + 1] - '0';
    //printf("returned int = %i\n", a*10+b);
    return (a*10 + b);
}

int main() {
    char grid[] = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";
    long long int max_product = 0;
    long long int product = 0;
    int x;
    int digits = 4;

    // Print out grid
    for (int row = 0; row < SIZE; row++ ) {
        for (int col = 0; col < SIZE; col++) {
            int a = getInt(grid, row*60 + col*3);
            if (a > 9) {
                printf("%i ", a);
            }
            else {
                printf("0%i ", a);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Check up/down
    for (int col = 0; col < SIZE; col++) {
        // Get initial product for col
        product = 1;
        for (int row = 0; row < digits; row++) {
            x = getInt(grid, row*60 + col*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int row = 0; row < SIZE - digits; row++) {
            // If ith value not zero, perform product update
            if (getInt(grid, row*60 + col*3) != 0) {
                product = product / getInt(grid, row*60 + col*3);
                product = product * getInt(grid, (row+digits)*60 + col*3);
            }
            // Else, skip zero and calculate new product from row after 00
            else {
                product = 1;
                for (int j = row+1; j < row + digits + 1; j++) {
                    x = getInt(grid, j*60 + col*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }
    printf("Finished up/down, max_product = %i\n", max_product);

    // Check left/right
    for (int row = 0; row < SIZE; row++) {
        // Get initial product for row
        product = 1;
        for (int col = 0; col < digits; col++) {
            x = getInt(grid, row*60 + col*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int col = 0; col < SIZE - digits; col++) {
            // If ith value not zero, perform product update
            if (getInt(grid, row*60 + col*3) != 0) {
                product = product / getInt(grid, row*60 + col*3);
                product = product * getInt(grid, row*60 + (col+digits)*3);
            }
            // Else, skip zero and calculate new product from col after 00
            else {
                product = 1;
                for (int j = col+1; j < col + digits + 1; j++) {
                    x = getInt(grid, row*60 + j*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }
    printf("Finished left/right, max_product = %i\n", max_product);


    // Check forward diagonal (below/including major forward diagonal)
    for (int row = SIZE - digits; row >= 0; row--) {
        // Get initial product for diagonal
        product = 1;
        int col = 0;
        for (int j = 0; j < digits; j++) {
            x = getInt(grid, (row+j)*60 + (col+j)*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int col = 0; col < SIZE - row - digits; col++) {
            // If ith value not zero, perform product update
            if (getInt(grid, (row+col)*60 + col*3) != 0) {
                product = product / getInt(grid, (row+col)*60 + col*3);
                product = product * getInt(grid, (row+col+digits)*60 + (col+digits)*3);
            }
            // Else, skip zero and calculate new product from diagonal after 00
            else {
                product = 1;
                for (int j = digits; j < digits + digits; j++) {
                    x = getInt(grid, (row+j)*60 + (col+j)*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Check forward diagonal (above major forward diagonal)
    for (int col = 1; col < SIZE - digits + 1; col++) {
        // Get initial product for diagonal
        product = 1;
        int row = 0;
        for (int j = 0; j < digits; j++) {
            x = getInt(grid, (row+j)*60 + (col+j)*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int row = 0; row < SIZE - col - digits; row++) {
            // If ith value not zero, perform product update
            if (getInt(grid, (row)*60 + (col+row)*3) != 0) {
                product = product / getInt(grid, (row)*60 + (col+row)*3);
                product = product * getInt(grid, (row+digits)*60 + (col+row+digits)*3);
            }
            // Else, skip zero and calculate new product from diagonal after 00
            else {
                product = 1;
                for (int j = 1; j < digits + 1; j++) {
                    x = getInt(grid, (row+j)*60 + (col+row+j)*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }    

    printf("Finished forward diagonal, max_product = %i\n", max_product);

    // Check backward diagonal (below/including major backward diagonal)
    for (int row = SIZE - digits; row >= 0; row--) {
        // Get initial product for diagonal
        product = 1;
        int col = 19;
        for (int j = 0; j < digits; j++) {
            x = getInt(grid, (row+j)*60 + (col-j)*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int col = SIZE - 1; col > row + digits - 1; col--) {
            // If ith value not zero, perform product update
            if (getInt(grid, (row-(col-(SIZE-1)))*60 + col*3) != 0) {
                product = product / getInt(grid, (row-(col-(SIZE-1)))*60 + col*3);
                product = product * getInt(grid, (row-(col-(SIZE-1))+digits)*60 + (col-digits)*3);
            }
            // Else, skip zero and calculate new product from diagonal after 00
            else {
                product = 1;
                for (int j = 1; j < digits + 1; j++) {
                    x = getInt(grid, (row-(col-(SIZE-1))+j)*60 + (col-j)*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Check backward diagonal (above major backward diagonal)
    for (int col = 18; col >= 0; col--) {
        // Get initial product for diagonal
        product = 1;
        int row = 0;
        for (int j = 0; j < digits; j++) {
            x = getInt(grid, (row+j)*60 + (col-j)*3);
            product = product * x;
        }
        if (product > max_product) {
            max_product = product;
        }

        // Update product
        for (int row = 0; row < col - digits + 1; row++) {
            // If ith value not zero, perform product update
            if (getInt(grid, row*60 + (col-row)*3) != 0) {
                product = product / getInt(grid, row*60 + (col-row)*3);
                product = product * getInt(grid, (row+digits)*60 + (col-row-digits)*3);
            }
            // Else, skip zero and calculate new product from diagonal after 00
            else {
                product = 1;
                for (int j = 1; j < digits + 1; j++) {
                    x = getInt(grid, (row+j)*60 + (col-row-j)*3);
                    product = product * x;
                }
            }

            if (product > max_product) {
                max_product = product;
            }
        }
    }  
    printf("Finished backward diagonal, max_product = %i\n", max_product);

    printf("Solution = %lli", max_product);
}