#include <stdio.h>
#include <math.h>

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician 
in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which 
is correct, is obtained by cancelling the 9s. We shall consider fractions like
30/50 = 3/5, to be trivial examples. There are exactly four non-trivial 
examples of this type of fraction, less than one in value, and containing two 
digits in the numerator and denominator. If the product of these four fractions 
is given in its lowest common terms, find the value of the denominator.



*/

// Function to find the greatest commor denominator of two numbers. Used to 
// simplify functions.
int gcd(int n, int m) {
    int gcd, remainder;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    return gcd;
}

int main() {
    int numerators[4] = {0};
    int denominators[4] = {0};
    int pos = 0;

    // A fraction of two two digit numbers with a repeated digit has three
    // unique digits: let i be the unique numerator digit, j the unique 
    // denominator digit, and k the repeated digit
    // i,j,k >= 1 since the numbers are two digit and repeated zeros are trivial
    // Possible fractions are ik/jk, ik/kj, ki/jk. ki/kj.
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                    // Form possible numerators (num1) and denominators (num2)
                    float num1_1 = 10*i+k;
                    float num2_1 = 10*j+k;
                    float num1_2 = i + 10*k;
                    float num2_2 = j + 10*k;

                    // Check if fraction meets the rule, if so add it to the lists
                    if (num1_1 < num2_1 && num1_1/num2_1 == (float)i/(float)j) {
                        numerators[pos] = num1_1;
                        denominators[pos] = num2_1;
                        pos++;
                    }
                    if (num1_1 < num2_2 && num1_1/num2_2 == (float)i/(float)j) {
                        numerators[pos] = num1_1;
                        denominators[pos] = num2_2;
                        pos++;
                    }
                    if (num1_2 < num2_1 && num1_2/num2_1 == (float)i/(float)j) {
                        numerators[pos] = num1_2;
                        denominators[pos] = num2_1;
                        pos++;                    
                    }
                    if (num1_2 < num2_2 && num1_2/num2_2 == (float)i/(float)j) {
                        numerators[pos] = num1_2;
                        denominators[pos] = num2_2;
                        pos++;                    
                    }
                }
        }
    }

    // Calculate product of the four fractions
    int numerator = 1;
    int denominator = 1;
    for (int i = 0; i < 4; i++) {
        numerator = numerator*numerators[i];
        denominator = denominator*denominators[i];
    }
    
    // Calculate the denominator of the simplified product
    int gcd1 = gcd(numerator, denominator);
    numerator = numerator/gcd1;
    denominator = denominator/gcd1;

    // Print solution
    printf("Denominator = %d", denominator);
}