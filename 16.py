import math

'''
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?

This can be solved by doing multiplication of numbers represented
as strings. doubleString() takes a number expressed as a string,
and returns a string of that number doubled. The main loop then 
calls this function the required number of times to find 2^1000.
Since we the base is 2, we only need a function to double a string,
rather than to multiply it by another string.
'''


def doubleString(s):
    '''
    doubleString() takes a number expressed as a string,
    and returns a string of that number doubled.
    '''
    length = len(s)
    carry = 0
    main = 0
    ans = ""

    # Loop backwards through string
    for i in range(length-1, -1, -1):
        # Calculate carry and main bits
        main = 0
        a = s[i]
        b = int(a)*2 + carry
        if (b > 9):
            carry = math.floor(b/10)
            main = b % 10
        else :
            carry = 0
            main = b
        # Update ans    
        ans = str(main) + ans
    
    # Add the carry on to the end if >0
    if carry > 0:
        ans = str(carry) + ans
    
    return ans

def main():
    power = 1000
    in_str = "2"

    # Loop over power
    for i in range(power-1):
        in_str = doubleString(in_str)

    print(f"2^1000 = {float(in_str)}")
    sum = 0

    # Find sum of digits
    for j in range(len(in_str)):
        sum += int(in_str[j])
    print(f"Solution = {sum}")

if __name__ == "__main__":
    main()