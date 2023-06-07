def compare(string1, i, string2): 
    len2 = len(string2)
    k = 0 
    
    while(k < len2): 
        if(string1[i + k] != string2[k]): 
            break
        k += 1

    if k == len2: 
        return i
    else: 
        return -1

def substr(string1, string2):
    len1 = len(string1)
    len2 = len(string2)

    for i in range(len1 - len2 + 1):
        result = compare(string1, i, string2)
        if result != -1: 
            return i 
    return -1

string1 = "Chhapra"
string2 = "pra"
print(substr(string1, string2))