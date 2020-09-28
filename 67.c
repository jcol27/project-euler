#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define new_max(x,y) ((x) >= (y)) ? (x) : (y)

// Find the maximum total from top to bottom of the triangle in triangle.txt

int main() {
    int triangle2[100][100] = {0};
    int length2 = 100;

    // Read in triangle
    FILE *file;
    file = fopen("67_triangle.txt", "r");

    if (file == NULL) {
        printf("Error reading file\n");
        exit(0);
    }

    int x = 0;
    int line = 0;
    int pos = 0;
    while (!feof(file)) {
        fscanf(file,"%d ", &x);
        if (pos <= line) {
            triangle2[line][pos] = x;
            pos++;
        }
        else {
            line++;
            pos = 0;
            triangle2[line][pos] = x;
            pos++;
        }
    }
    fclose(file);

    int total = 0;
    for (int i = length2 - 2; i >= 0; i--) {
        int row2_temp[100] = {0};
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