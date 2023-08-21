#include <function.h>

/** 
 * In C, these is standard include <for header files> path and standard library path 
 * Our header file does not exist in standard include path, hence point it with -I flag of gcc 
 * -I. : include . (current dir) in current standard include path, or look for header files here as well

 * -L. : look for library or function definitions while creating total program's exe here. 
 * -ltest: In linux world, we mention external library after removing some words from its name 
 *	libtest.so: -ltest 
 * 	remove ib.so from name to point to this shared object file. This is convention
 */


 /**
 * Before doing anything with linker, let's tell dynamic link LOADER where to find this libtest.so: 
 * 	export LD_LIBRARY_PATH="/MSTC/023. Library_and_Linking/Client1"

 * Compiling the code:
 * 	gcc -I. -L. client.c -ltest
 * Telling the linker to link libtest.so (-ltest) from current directory (-L.)
 * 	
 */

/**
 * ldd a.out : gives the virtual address of found libraries and tells if any library is missing
 */

int main(void) {
	function1(); 
	function2();
}

/**
 * Symbol function1 and function2 will be impoted into exe and finally given virtual address 
 * This is implicit dynamic linking
 */ 


/**
 * Alternatively if you do not want to point current dir into standard include path. 
 * Use double quotes to include header file  
 * #include "header.h"
 */
