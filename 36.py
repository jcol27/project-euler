import math

'''
The decimal number, 585 = 1001001001_2 (binary), is palindromic 
in both bases. Find the sum of all numbers, less than one million, 
which are palindromic in base 10 and base 2. Note: the palindromic 
number, in either base, may not include leading zeros.


'''

'''
Converts a number represented as a string into binary
'''
def to_binary(num_string):
    return str(bin(int(num_string)))[2:]

'''
Checks if a number represented as a string is palindromic
'''
def is_palindrome(n):
    palindrome = True
    for i in range(int(len(n)/2)):
        if (n[i] != n[len(n)-i-1]):
            palindrome = False
            break
    return palindrome

sum = 0
for i in range(1,1000000):
    i = str(i)
    if is_palindrome(i):
        if is_palindrome(to_binary(i)): 
            sum += int(i)

print(f"Solution = {sum}")