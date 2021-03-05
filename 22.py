import math

'''
Using names.txt (right click and 'Save Link/Target As...'), a 46K 
text file containing over five-thousand first names, begin by sorting 
it into alphabetical order. Then working out the alphabetical value 
for each name, multiply this value by its alphabetical position in 
the list to obtain a name score.

What is the total of all the name scores in the file?
'''

# Read input file of names into a list
with open("22_names.txt") as file:
    lines = file.read().splitlines()
    lines = lines[0].split(",")
    for i in range(len(lines)):
        lines[i] = lines[i].replace('\"','')
    sorted_names = sorted(lines)

# Loop through names and evaluate the name score for each
total_value = 0
for pos, name in enumerate(sorted_names):
    value = 0
    for char in list(name):
        value += (ord(char) - 64)
    total_value += value*(pos+1)

print(f"Total score = {total_value}")

    
        
