//sum of n terms in array

#include <stdio.h> 

int sum(int* arr, int index) {

    if(index == 0) 
        return arr[index]; 
    else if(index > 0) 
        return arr[index] + sum(arr, index - 1);
}

int main(void) {

    int arr[] = {10, 20, 30, 40, 50};
    printf("%d\n", sum(arr, 4));
}

//f(n) = n^2
void square(int n) {

    return n * n;
}