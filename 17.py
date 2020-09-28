import math

# If all the numbers from 1 to 1000 (one thousand) 
# inclusive were written out in words, how many letters would be used? 

def evalOnes(a):
    if (a == 1 or a == 2 or a == 6):
        return 3
    elif (a == 4 or a == 5 or a == 9):
        return 4
    elif (a == 3 or a == 7 or a == 8):
        return 5
    elif (a == 0):
        return 0

def evalTensAndOnes(a):

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
    b = int(math.floor(a/1000))
    return evalOnes(b) + 8

def evalNum(a):
    if a < 10:
        return evalOnes(a)
    elif a < 100:
        return evalTensAndOnes(a)
    elif a < 1000:
        return evalTensAndOnes(a) + evalHundreds(a)
    elif a < 10000:
        #print(evalThousands(a))
        return evalThousands(a) + evalHundreds(a) + evalTensAndOnes(a)
    else:
        print("Error: number outside range (1-9999)")


print(f"Num = {1000}, count = {evalNum(1000)}")


count = 0
for i in range(1,1001):
    count += evalNum(i)
    #print(f"Just evaluated {i}")

print(f"Total count = {count}\n")