/*
    @AUTHOR: ABHIJEET RAI 
    @DATE: 24/11/22
    @GOAL: To demonstrate the use of scanf_s
*/

#include <stdio.h>
void exit(int exit_code); 

int main(void) {

    long long n; 
    printf("Enter integer within 64 bit range:");
    scanf_s("%lld", &n);
    printf("n = %lld\n", n);
    exit(0);
}

/*
It is a function that belongs specifically 
to the Microsoft compiler.
scanf originally just reads whatever console 
input you type and assign it to a type of variable.

If you have an array called first_name[5] and you use scanf for "Alex", there is no problem. 
If you have the same array and assign "Alexander", you can see it exceeds the 5 slots that the array contains, 
C will still write it on memory that doesn't belong to the array and it might or might not crash the program, 
depending if something tries to access and write on that memory slot that doesn't belongs to first_name. 
This is where scanf_s comes in.

scanf_s has an argument(parameter) where you can specify the buffer size and 
actually control the limit of the input so you don't crash the whole building.
*/