/*
 * Compiler my choose to entertain or ignore the inline keyword. 
 * When a function is declared inline, ideally calling overhead to that function is reduced. (Prologue and Epilogue)
 * Callee inline function's assembly code is generated in caller, ideally. 
 * The inline function unlike other functions does not have external linkage(by default) unless explicitly speicifed, 
 * hence static class is often used for inline functions
*/

#include <stdio.h>
#include <stdlib.h> 
#include "myheader.h"

int main(void) {
    int val = 0;

    val = my_square(11);
    printf("%d\n", val);

    return (0);
}