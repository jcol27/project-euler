#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
214132412341234123412341243231412341234

Solved by finding the permutations sequentially by finding the
last decreasing subsequence in the current permutation, swapping 
positions i and j, and reversing i to n. This solves very quickly 
compare to brute force methods.
*/

/*
Reverses an array of length n from {start} to the end of the array
*/
void reverse(int arr[], int start, int n)
{
    for (int low = start, high = n-1; low < high; low++, high--)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}

int compare( const void* a, const void* b)
{
   int int_a = * ( (int*) a );
   int int_b = * ( (int*) b );

   // An easy expression for comparing
   return -((int_a > int_b) - (int_a < int_b));
}

int main() {
    int n = 9;
    int perm[9] = {1,2,3,4,5,6,7,8,9};
    int count = 1;
    int sum = 0;
    int pos = 0;
    int products[100] = {0};

    // Loop over all permutations (9!)
    while (count < 362880) {
        int i, j, k, temp;        
        
        // Find last decreasing subsequence
        for (i = n - 1; i > 0 && perm[i-1]>perm[i]; i--) {
            ;
        }
        if (i == 0) {
            break;
        }
        for (j = i + 1; j < n && perm[i-1] < perm[j]; j++) {
            ;
        }

        // Swap positions i and j and reverse the array from i to n
        temp = perm[j-1];
        perm[j-1] = perm[i-1];
        perm[i-1] = temp;
        reverse(perm, i, n);
        count = count + 1;

        // Find all multiplicand/multiplier/product combinations of
        // the current permutation
        // Since num1 and num2 must have at least one digit, x >= 1
        // and y >= 1. Since a five digit number multiplied by a 
        // single digit number must be at least five digits, x <= 4
        // and y <= 4
        for (int x = 1; x < 5; x++) {
            for (int y = 1; y < 5; y++) {
                int num1 = 0;
                for (int a = 0; a < x; a++) {
                    num1 += perm[a]*pow(10,x-a-1);
                }  
                int num2 = 0;
                for (int b = x; b < x+y; b++) {
                    num2 += perm[b]*pow(10,x+y-b-1);
                }  
                int num3 = 0;
                for (int c = x+y; c < n; c++) {
                    num3 += perm[c]*pow(10,n-c-1);
                }  
                if (num1*num2 == num3) {
                    printf("%d x %d = %d\n", num1, num2, num3);
                    products[pos] = num3;
                    pos += 1;
                }
            }
        }
    }

    // Sort products (makes processing duplicates much easier)
    qsort(products, 100, sizeof(int), compare);

    // Remove duplicates
    pos = 0;
    int last_unique = 999999999;
    while (products[pos] != 0) {
        if (products[pos] < last_unique) {
            sum += products[pos];
            last_unique = products[pos];
        }
        pos++;
    }

    // Print the solution
    printf("Solution is: %d", sum);
}