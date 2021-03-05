#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*
What is the sum of the digits of the number 2^1000?

SEE 16.py
*/
const char* doubleString(char num[]) {
    // Takes a number in the form of a string and doubles it
    // Returns the result as a string
    int length = strlen(num);
    //char ans[length+1];
    char *ans = malloc (sizeof (char) * (length+1));
    int carry = 0;

    for (int i = length-1; i >= 0; i--) {
        int main = 0;
        int a = num[i] - '0';
        int b = a*2 + carry;
        if (b > 9) {
            carry = floor(b/10);
            main = b % 10; 
        }
        else {
            main = b;
            carry = 0;
        }
        ans[i+1] = main + '0';
    }

    //if (ans[0] == '\000') {
    //    memmove (ans, ans+1, strlen (ans+1) + 1);
    //}

    return ans;
}

int main() {
    printf("hello");
    char new[] = "123";
    printf("%s", doubleString("0123"));
}