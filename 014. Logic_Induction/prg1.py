a = int(input("Enter integer 1: "))
b = int(input("Enter integer 2: "))
c = int(input("Enter integer 3: "))

max = 0 

if a >= b: 
    if a >= c: 
        max = a 
    else: 
        max = c 

else: 
    if b >= c: 
        max = b 
    else: 
        max = c

print(max)  