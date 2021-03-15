#include <stdio.h>
#include <math.h>

/*
If p is the perimeter of a right angle triangle with integral length 
sides, {a,b,c}, there are exactly three solutions for p = 120:
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p ≤ 1000, is the number of solutions maximised?

A set of positive integers a, b, c such that a^2 + b^2 = c^2 are known
as a Pythagorean triple. These can be generated with the formula:
a = k*(m^2-n^2), b = k*(2mn), c = k*(m^2+n^2) for any integers m,n,k with
m>n>0 and k>0.

Then to avoid duplicates we just need to keep track of the a,b pairs and
check each new pair against the previously found pairs. This sounds more
annoying than it actually is, although in a language with easy dynamic
arrays like python it would be easier.

Finally to set the upper limits for m and n. Setting limits like 1000 would
be good enough for this case, but we can calculate the actual limits using
the formula for p and the Pythagorian triple formulas. Since m>n, there are 
two practical edge cases: n = 1 and n = m-1. We should also note that k must
be > 0 and < p. 
If n = 1:
        m^2 + m - 500/k < 0 
        m < -1/2 +- (1/2)*sqrt(1+p/k)
        Smaller k gives bigger bound so assume that.
        m < -1/2 + (1/2)*sqrt(1+2*p)
If n = m - 1:
        4km^2 - 2km - 1000 < 0
        m < -1/4 + (1/2)*sqrt((1/2)^2+p/k)
        Smaller k gives bigger bound so assume that.
        m < -1/4 + (1/2)*sqrt(1/4 + p)
        
Then take larger of the two.
*/

#define new_max(x,y) ((x) >= (y)) ? (x) : (y)

int main() {
    int counts[1000][50] = {0};
    int a,b,c,prev, max_k;
    int p = 1000;

    // Practical limit for m (and thus n)
    int limit_m = new_max( (int)(-0.5 + 0.5*pow(1+2*p,0.5f)), (int)(-0.25 + 0.5*pow(0.25+p, 0.5f)) ) + 1;

    // Loop for m and n, arbitrary ints
    for (int n = 1; n < limit_m; n++) {
        for (int m = n + 1; m < limit_m + 1; m++) {
            // Caculate a, b, c
            a = pow(m,2) - pow(n,2);
            b = 2*m*n;
            c = pow(m,2) + pow(n,2);
            
            // Calculate the max_k depending on whether p/(a+b+c) is integer
            if (p % (a+b+c) == 0) {
                max_k = p/(a+b+c);
            }
            else {
                max_k = (int) (p/(a+b+c)) + 1;
            }

            // Loop over possible k's where the sum k(a+b+c) < p
            for (int k = 1; k < max_k; k++) {
                prev = 0; // Boolean for if a,b or b,a has been counted previously

                // Loop over previously recorded a,b pairs and check both permutations
                for (int j = 0; j < counts[k*(a+b+c)][1]; j++) {
                    if (a*k == counts[k*(a+b+c)][j*2+2] && b*k == counts[k*(a+b+c)][j*2+3] || b*k == counts[k*(a+b+c)][j*2+2] && a*k == counts[k*(a+b+c)][j*2+3]) {
                        prev = 1;
                    }
                }

                // If a,b has not been counted yet, add it to the total and pairs list
                if (prev == 0) {
                    counts[k*(a+b+c)][0] += 1;
                    counts[k*(a+b+c)][counts[k*(a+b+c)][1]+2] = k*a;
                    counts[k*(a+b+c)][counts[k*(a+b+c)][1]+3] = k*b;
                    counts[k*(a+b+c)][1] += 2;
                }
            }
        }
    }

    // Loop over the counts[][0] array to find the value of p with the largest number of sols
    int best_p = -1;
    int best_sol = -1;
    for (int i = 0; i < 1000; i++) {
        if (counts[i][0] > best_sol) {
            best_p = i;
            best_sol = counts[i][0];
        }
    }

    // Print solution
    printf("Solution = %d", best_p);
}