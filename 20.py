import math

# n! means n × (n − 1) × ... × 3 × 2 × 1
# For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
# Find the sum of the digits in the number 100!

# Multiply a string by a single digit number
def stringSingleMulti(string, num):
    string = "0" + string
    carry_bit = 0
    result = ""
    for i in range(len(string)-1, 0, -1):
        a = int(string[i])*num
        a = a + carry_bit
        result = str(a % 10) + result
        carry_bit = math.floor(a/10)
    if carry_bit != 0:
        result = str(carry_bit) + result

    return result

# Multiply a string by a two digit number
def stringDoubleMulti(string, num):
    string1 = stringSingleMulti(string, num % 10)
    string2 = stringSingleMulti(string, math.floor(num/10)) + "0"
    return stringAdd(string1, string2)

# Adds two strings
def stringAdd(string1, string2):
    if (len(string2) > len(string1)):
        temp = string1
        string1 = string2
        string2 = temp
    if (len(string1) > len(string2)):
        carry = 0
        result = ""
        for i in range(0, len(string2)):
            sum_bit = int(string1[-1-i]) + int(string2[-1-i])
            a = sum_bit + carry
            result = str(a % 10) + result
            carry = math.floor(a/10)
        for j in range(len(string2), len(string1)):
            a = carry + int(string1[-1-j])
            result = str(a % 10) + result
            carry = math.floor(a/10)
    if (len(string1) == len(string2)):
        carry = 0
        result = ""        
        for i in range(0, len(string2)):
            sum_bit = int(string1[-1-i]) + int(string2[-1-i])
            a = sum_bit + carry
            result = str(a % 10) + result
            carry = math.floor(a/10)

        result = str(carry) + result       

    return result

# Sums the digits of a number given as a string
def sumDigits(string):
    sum_digits = 0
    for i in range(len(string)):
        sum_digits += int(string[i])

    return sum_digits

# Main
num = "1"
for i in range(1, 100):
    if i < 10:
        num = stringSingleMulti(num, i)
    else:
        num = stringDoubleMulti(num, i)
ans = sumDigits(num)

print(f"Sum of digits = {ans}")
