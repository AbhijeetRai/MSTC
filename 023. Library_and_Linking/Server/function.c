/**
 * gcc -fPIC -c function.c: 				function.o is generated 
 * gcc --shared -o libtest.so function.o		libtest.so is generated
 */

#include <stdio.h>

extern void function1(void) {
	puts("function1");
}
 
extern void function2(void) {
	puts("function2");
}

/**
 * This file does not have main, hence it cannot be translated into exe but library 
 * An independent C source file is known as compilation unit or translation unit. 
 * Some translation units are complete programs, some are not. 
 * 
 * Symbols (var/funcs) in library (object) file are not assigned final virtual address 
 * until they are linked to a process. These are called relocatable object file or PIC(position independent code)
 */
