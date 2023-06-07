#HackerRank question: https://www.hackerrank.com/challenges/recursive-digit-sum/problem?isFullScreen=true

def superDigit(n): 
    sum = 0
    
    if len(n) == 1: 
        return n
    
    else: 
        for i in n: 
            sum += int(i)
        return superDigit(str(sum))

n = str(138)  
k = 3

sum = 0
for i in n: 
    sum += int(i)
sum = sum * k
n = str(sum)
print(superDigit(n))