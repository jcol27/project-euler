import math

'''
A perfect number is a number for which the sum of its proper 
divisors is exactly equal to the number. For example, the sum 
of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, 
which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors 
is less than n and it is called abundant if this sum exceeds n.

Find the sum of all the positive integers which cannot be written 
as the sum of two abundant numbers.
'''

# Find all abundant numbers less than or equal to 28123
abundants = []
for i in range(1,28124):
    divisors = []
    for j in range(1,math.floor(i/2)+1):
        if (i % j == 0):
            divisors.append(j)
    if (sum(divisors) > i):
        abundants.append(i)

# Create list of positive integers which can be written as the sum of two positive abudants
pos_ints = []
for i in abundants:
    for j in abundants:
        pos_ints.append(i+j)

sorted_pos_ints = list(set(sorted(pos_ints)))

# Find positive integers which can be written as the sum of two positive integers
sum_ints = 0
pos_ints = []
for i in range(1,28124):
    if i not in sorted_pos_ints:
        sum_ints += i

print(f"Sum of positive ints = {sum_ints}")

