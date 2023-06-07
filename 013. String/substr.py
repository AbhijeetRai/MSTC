def substr(string1, string2):
    
    len1 = len(string1)
    len2 = len(string2)
    N = len1 - len2 + 1

    for i in range(N):

        k = 0
        while(k < len2):
            if(string1[i + k] != string2[k]):
                break 
            k += 1

        if k == len2: 
            return i;

    return -1

string1 = "Chhapra"
string2 = "hh"
print(substr(string1, string2))