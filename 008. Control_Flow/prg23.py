
#partition considering last element as pivot
def partition(arr):

    pivot = arr[0] 
    n = len(arr) - 1
    i = n + 1

    for j in range(n, 0, -1):
        if(arr[j] >= pivot):
            i -= 1 
            arr[i], arr[j] = arr[j], arr[i] 

    i -= 1
    j -= 1 
    arr[i], arr[j] = arr[j], arr[i] 

arr = [8, 77, -1, 34, 31, 556, 6]
partition(arr) 
print(arr) 