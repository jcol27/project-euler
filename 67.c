#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define new_max(x,y) ((x) >= (y)) ? (x) : (y)

/* 
Find the maximum total from top to bottom of the triangle in triangle.txt

Similarly to problem 18, this can be solved by working from the bottom 
up in the style of a min-max algorithm. For example, a node with two 
children can be written as the sum of the node itself and its larger 
child. Then by working back up the tree, by getting to the root node 
we can find the sum of the largest path.
*/

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

    // Loop from the bottom of the triangle upwards
    int total = 0;
    for (int i = length2 - 2; i >= 0; i--) {
        int row2_temp[100] = {0};

        // Loop across a row of the triangle
        for (int j = 0; j < i + 1; j++) {
            // Find which sum is larger
            int sum1 = 0;
            int sum2 = 0;
            sum1 += triangle2[i][j];
            sum2 += triangle2[i][j];
            sum1 += triangle2[i+1][j];
            sum2 += triangle2[i+1][j+1];
            row2_temp[j] = new_max(sum1, sum2);
        }
        // Update the triangle
        for (int k = 0; k < length2; k++) {
            triangle2[i][k] = row2_temp[k];
        }
    }
    total = triangle2[0][0];
    printf("Solution = %i", total);
}