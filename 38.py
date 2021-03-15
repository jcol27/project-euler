import math
import itertools
from itertools import chain, combinations

'''
Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

What is the largest 1 to 9 pandigital 9-digit number that can be formed 
as the concatenated product of an integer with (1,2, ... , n) where n > 1?

--------------------------------------------------------------------------

Since num*1 must be included in the concatinated product, and concatinated
products cannot have repeating digits, num cannot have repeating digits. To
generate valid numbers of this form we can use itertools.permutations which
dramatically reduces the number of evaluations we have to do.

Using a somewhat inelegant try/except block to loop through the itertools
objects for various lengths of permutations. Works fine though.
'''

# Create initial iterable and variables
iterables = itertools.permutations([1,2,3,4,5,6,7,8,9],1)
num = 0
count = 1
best = 0

# Since n > 1, the max num can be is some 4 digit value, so
while num < 9999:
    try:
        # Try getting the next value from the current iterable
        # and if there is one then convert from tuple to int
        num = int("".join(str(s) for s in iterables.__next__()))

        # Loop over possible n's, n>1, n can't be larger than 9 over
        # the length since len*n <= 9 for the concatenation
        for n in range(2,int(9/len(str(num)))+1):
            nums = []
            pandigital = True

            # Create list of products
            for j in range(1,n+1):
                nums.append(str(num*j))
            
            # Check that each digits appears exactly once in nums
            digits = [0]*9
            for x in nums:
                for k in range(9):
                    if (str(k+1) in x):
                        digits[k] += 1
            
            # Check that the products concatinate to a str of len 9
            if sum(len(s) for s in nums) == 9:
                for i in range(9):
                    if digits[i] != 1:
                        pandigital = False
                        break
                # If pandigital, update best
                if (pandigital):
                    sol = int("".join(nums))
                    if sol > best:
                        best = sol
    # If end of current iterable reached (e.g. (9,9,9) for count = 3)
    # increment count and update the iterable
    except:
        if count < 9:
            count += 1
            iterables = itertools.permutations([1,2,3,4,5,6,7,8,9],count)

print(f"Solution is {best}")
        
