#include <stdio.h>
#include <math.h>
#define new_max(x,y) ((x) >= (y)) ? (x) : (y)

// Find the maximum total from top to bottom of the triangle below:

int main() {
    int triangle1[4][4] = {{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};
    int length1 = 4;
    int triangle2[15][15] = {{75}, {95, 64}, {17, 47, 82}, {18, 35, 87, 10}, {20, 4, 82, 47, 65}, {19, 1, 23, 75, 3, 34}, {88, 2, 77, 73, 7, 63, 67}, {99, 65, 4, 28, 6, 16, 70, 92}, {41, 41, 26, 56, 83, 40, 80, 70, 33}, {41, 48, 72, 33, 47, 32, 37, 16, 94, 29}, {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14}, {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57}, {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48}, {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31}, {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
    int length2 = 15;

    int total = 0;
    for (int i = length2 - 2; i >= 0; i--) {
        int row2_temp[15] = {0};
        for (int j = 0; j < i + 1; j++) {
            int sum1 = 0;
            int sum2 = 0;
            sum1 += triangle2[i][j];
            sum2 += triangle2[i][j];
            sum1 += triangle2[i+1][j];
            sum2 += triangle2[i+1][j+1];
            row2_temp[j] = new_max(sum1, sum2);
        }
        for (int k = 0; k < length2; k++) {
            triangle2[i][k] = row2_temp[k];
        }
    }
    total = triangle2[0][0];
    printf("Solution = %i", total);
}