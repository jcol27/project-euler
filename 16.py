import math

def doubleString(s):
    length = len(s)
    carry = 0
    main = 0
    ans = ""

    for i in range(length-1, -1, -1):
        main = 0
        a = s[i]
        b = int(a)*2 + carry
        if (b > 9):
            carry = math.floor(b/10)
            main = b % 10
        else :
            carry = 0
            main = b
        ans = str(main) + ans
    
    if carry > 0:
        ans = str(carry) + ans
    
    return ans

def main():
    power = 1000
    in_str = "2"
    for i in range(power-1):
        in_str = doubleString(in_str)
        #print(f"product = {in_str}")

    print(f"2^1000 = {float(in_str)}")
    sum = 0
    for j in range(len(in_str)):
        sum += int(in_str[j])
    print(f"Solution = {sum}")

if __name__ == "__main__":
    main()