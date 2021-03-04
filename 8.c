#include <stdio.h>
/*
Find the thirteen adjacent digits in the 1000-digit number 
that have the greatest product. What is the value of this product?

Problems like this with long numbers are best done with strings.
String manipulation is much easier in Python, but this one I did
in C just to see. Optimized by storing the product of a given 
thirteen numbers, then dividing by the number passed and multiplying
by the next. Special logic for dealing with zeros.
*/

int main() {
    int length = 1000;
    char num[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    int digits = 13;
    long long int max_product = 0;
    long long int product, x;

    // Initial product (first 13 digits)
    product = 1;
    for (int j = 0; j < digits; j++) {
        x = num[j] - '0';
        product = product * x;
    }
    max_product = product;

    // Loop through number string
    for (int i = 0; i < length - digits; i++) {
        
        // If ith digit not zero, perform product update
        if ((num[i]- '0') != 0) {
            product = product / (num[i]- '0');
            product = product * (num[i+digits]- '0');
        }
        // Else, skip zero and calculate new product from {digits} digits after i
        else {
            product = 1;
            for (int j = i+1; j < i + digits + 1; j++) {
                x = num[j] - '0';
                product = product * x;
            }
        }
        // Update max_product
        if (product > max_product) {
            max_product = product;
        }
    }
    printf("Solution = %lli", max_product);
}