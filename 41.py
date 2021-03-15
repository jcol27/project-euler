import math
import itertools

'''
We shall say that an n-digit number is pandigital if it makes 
use of all the digits 1 to n exactly once. For example, 2143 
is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?

Can use itertools similar to previous problem. We can use the 
rule than a number is divisible by three if and only if the 
sum of the digits of the number is divisible by three to see 
that for pandigital numbers, only those with 4 or 7 digits can
be prime.
'''

'''
Function to find if a number is prime, simply
checks if a number is divisible by values other
than one and itself.
'''
def is_prime(num):
    if (num == 0 or num == 1):
        return 0

    for i in range(2, math.floor(num/2) + 1):
        if (num % i == 0):
            return False
    return True


# Create initial iterable and variables
num = 0
count = 1
best = 0

# Since we only care about the largest, start at largest possible
# and stop at first solution
while best == 0:

    # Iterable for 7 digit pandigital numbers
    iterables = itertools.permutations(list(range(7,0,-1)),7)
    for num in iterables:
        num = int("".join(str(s) for s in num))
        # Check if prime
        if (is_prime(num) and num > best):
            best = num
            break
    
    # Iterable for 4 digit pandigital numbers
    if best != 0:
        iterables = itertools.permutations(list(range(4,0,-1)),4)
        for num in iterables:
            num = int("".join(str(s) for s in num))
            # Check if prime
            if (is_prime(num) and num > best):
                best = num
                break

print(f"Solution = {best}")