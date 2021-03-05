import math

'''
If all the numbers from 1 to 1000 (one thousand) 
inclusive were written out in words, how many letters would be used? 
Note: Do not count spaces or hyphens. For example, 342 (three hundred 
and forty-two) contains 23 letters and 115 (one hundred and fifteen) 
contains 20 letters. The use of "and" when writing out numbers is in 
compliance with British usage.

This can be done by splitting each number into its digits according to
their position, with the final two digits kept together. Then each of 
these digits can be evaluated separately to find the number of letters
based on the digits and their position.
'''

def evalOnes(a):
    '''
    Evaluates the number of letters used by a single digit
    '''
    if (a == 1 or a == 2 or a == 6):
        return 3
    elif (a == 4 or a == 5 or a == 9):
        return 4
    elif (a == 3 or a == 7 or a == 8):
        return 5
    elif (a == 0):
        return 0

def evalTensAndOnes(a):
    '''
    Evaluates the number of letters used by a two digit pair (in the
    final two places e.g. 17 = seventeen)
    '''
    if (a > 99):    
        a = int(str(a)[-2:])

    if (a < 10):
        return evalOnes(a)
    elif (a < 20):
        if (a == 10):
            return 3
        elif (a == 11 or a == 12):
            return 6
        elif (a == 15 or a == 16):
            return 7
        elif (a == 13 or a == 14 or a == 18 or a == 19):
            return 8
        elif (a == 17):
            return 9
    else:
        b = int(math.floor(a/10))
        if (b == 4 or b == 5 or b == 6):
            return 5 + evalOnes(a - (b*10))
        elif (b == 2 or b == 3 or b == 8 or b == 9):
            return 6 + evalOnes(a - (b*10))
        elif (b == 7):
            return 7 + evalOnes(a - (b*10))

def evalHundreds(a):
    '''
    Evaluates the number of letters used by a digit in the hundreds
    place
    '''
    if (a > 999):    
        a = int(str(a)[-3:])
        print(a)

    b = int(math.floor(a/100))
    if int(str(a)[-3:]) == 0:
        return 0
    if int(str(a)[-2:]) == 0:
        return evalOnes(b) + 7 
    else:
        return evalOnes(b) + 7 + 3

def evalThousands(a):
    '''
    Evaluates the number of letters used by a digit in the thousands
    place
    '''
    b = int(math.floor(a/1000))
    return evalOnes(b) + 8

def evalNum(a):
    '''
    Evaluates the number of letters in a number as a whole by breaking
    it down into digits based on position
    '''
    if a < 10:
        return evalOnes(a)
    elif a < 100:
        return evalTensAndOnes(a)
    elif a < 1000:
        return evalTensAndOnes(a) + evalHundreds(a)
    elif a < 10000:
        return evalThousands(a) + evalHundreds(a) + evalTensAndOnes(a)
    else:
        print("Error: number outside range (1-9999)")

# Calculate the number of letters in the numbers 1-1000 inclusive
count = 0
for i in range(1,1001):
    count += evalNum(i)

print(f"Total count = {count}\n")