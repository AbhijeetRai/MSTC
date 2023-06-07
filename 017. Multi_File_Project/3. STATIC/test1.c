/**
 * static when put in global variable and function declaration, limits visibility of 
 * global variable and function to that file only, where they are defined
*/

/**
 * If a global variable is declared static in a file, it is visible in that file only
 * If a function is declared static in a file, it is visible in that file only
*/

#include <stdio.h> 

float g_num; 
static int num; 

static void f(void) {
    puts("Inside f()");
}

void g(void) {
    puts("Inside g()");
}