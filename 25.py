import math
'''
What is the index of the first term
in the Fibonacci sequence to contain 1000 digits?
'''

def add(a, b):
    '''
    Add two numbers expressed as strings
    See earlier problems for commented method
    '''
    carry = 0
    c = ""
    if (len(b) > len(a)):
        for i in range(len(a)-1,-1,-1):
            temp = int(a[i]) + int(b[i+1]) + carry
            if (temp > 9):
                carry = math.floor(int(temp)/10)
                main = temp % 10
            else :
                carry = 0
                main = temp
            c = str(main) + c
       
        for j in range(len(b)-len(a)-1, -1, -1):
            temp = int(b[j]) + carry
            if (temp > 9):
                carry = math.floor(int(temp)/10)
                main = temp % 10
            else :
                carry = 0
                main = temp
            c = str(main) + c
        
        if carry > 0:
            c = str(carry) + c

    else:
        for i in range(len(a)-1,-1,-1):
            temp = int(a[i]) + int(b[i]) + carry
            if (temp > 9):
                carry = math.floor(int(temp)/10)
                main = temp % 10
            else :
                carry = 0
                main = temp
            c = str(main) + c     

        if carry > 0:
            c = str(carry) + c  

    return c


def main():
    a = "5"
    b = "3"
    print(f"{a}+{b}={add(a,b)}")


    index = 2
    digits = 1
    a = "1"
    b = "1"

    # Loop until goal reached
    while (digits < 1000):
        c = add(a,b)
        a = b
        b = c
        index += 1
        digits = len(c)
    
    print(f"Index = {index}")
    


if __name__ == "__main__":
    main()