/*
    @AUTHOR: ABHIJEET RAI 
    @DATE: 25/11/22
    @GOAL: To demonstrate the concept of blocking function with help of 
            _getch function (windows)
*/

#include <stdio.h>      //standard input output function declaration
#include <stdlib.h>     //standard library function declaration 
#include <conio.h>      //console input output function declaration 

int main(void) {

    char c; 
    printf("Start of program\n");
    c = _getch();       //can accept only one character or key or only one ascii code is returned 
    printf("c = %c\n", c);
    printf("End of program\n");
    exit(0);
}

