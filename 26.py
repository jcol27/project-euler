import math

'''
Find the value of d < 1000 for which 1/d contains the 
longest recurring cycle in its decimal fraction part.

Solved using long division of numbers represented through 
strings

'''

# Does long division on strings, allowing for much larger numbers than 
# python numeric types allow
def longDivision(num_string, divisor):

    idx = 0
    frac = ""
    temp = int(num_string[idx])

    # Move to first possible division
    while (temp < divisor):
        temp = temp * 10 + int(num_string[idx+1])
        frac += "0"
    
    # Division loop, add quotient to frac and calculate new temp based on the remainder
    while ((len(num_string)) > idx+1):
        frac += str(int(math.floor((temp/divisor))))
        temp = (temp % divisor) * 10 + int(num_string[idx+1])
        idx += 1

    # Unnecessary in this specific application
    if (len(frac) == 0):
        return "0"

    return frac

# Finds the longest cycle in a given string
def find_longest_cycle(dec_string):

    candidate = ""
    length = 0
    i = 0
    while i < (len(dec_string)):
        # Loop until value is repeated
        while dec_string[i] not in candidate:
            candidate += dec_string[i]
            i += 1
        
        # Value has been repeated, get cycle from candidate and get part of dec-string beginning at the cycle
        cycle = candidate[candidate.find(dec_string[i]):]
        new_string = dec_string[candidate.find(cycle):]
        
        # Loop to remove iterations of the cycle to find what is left
        while new_string.find(cycle) == 0:    
            new_string = new_string[len(cycle):]
        
        # Imperfect check to see if remaining part of new_string could be the first part of the cycle
        # Awkward because of dec strings like 0.002340000000000, where the last part of new_string matches
        # the first part of the dec_string, but clearly 00234 is not a cycle. The second part of the if statement
        # should mostly account for this, and it works enough to solve this problem
        if len(new_string) < len(cycle) and len(new_string) < len(dec_string) - 2*len(cycle):
            length = len(cycle)
            break
        else:
            # Otherwise, continue adding to the current cycle
            candidate += dec_string[i]
            i += 1

    # Check that the cycle isn't zeros or just the entire string (necessary for non repeating fractions
    # like 0.250000000)
    if (cycle == len(cycle)*"0" or cycle == dec_string):
        length = 0

    return cycle, length

# Main loop to find solution for [2,1000]
longest_d = -1
longest_cycle = ""
longest_length = -1
for i in range(2,1000):
    long_num = "1" + "0"*10000
    frac = longDivision(long_num, i)
    cycle, length = find_longest_cycle(frac)
    if length > longest_length:
        longest_d = i
        longest_cycle = cycle
        longest_length = length

print(f"Longest cycle: d = {longest_d}, frac = {longDivision(long_num, longest_d)}, cycle = {longest_cycle}, length = {longest_length}")
