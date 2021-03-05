#include <stdio.h>
#include <math.h>

/*
A permutation is an ordered arrangement of objects. If all of 
the permutations are listed numerically or alphabetically, 
we call it lexicographic order. 
What is the millionth lexicographic permutation of the 
digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

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

int main() {
    int n = 10;
    int perm[10] = {0,1,2,3,4,5,6,7,8,9};
    int count = 1;

    // Loop up to one millionth permutation
    while (count < 1000000) {
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
    }

    // Print the solution
    printf("Solution is: ");
    for (int i = 0; i < n; i++) {
        printf("%d", perm[i]);
    }
}