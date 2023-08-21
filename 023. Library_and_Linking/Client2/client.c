#include <stdio.h>
#include <function.h>

/**
 * Pahle hi copied library and header file to standard include and library path from server folder 
 * root@ubuntu-VirtualBox:/home/ubuntu/MSTC/023. Library_and_Linking/Server# cp function.h /usr/include/
 * root@ubuntu-VirtualBox:/home/ubuntu/MSTC/023. Library_and_Linking/Server# cp libtest.so /usr/lib/

 * cp function.h /usr/include/
 * cp libtest.so /usr/lib/

 * While compiling just link the library now: 
	gcc client.c -ltest
 */

int main(void) {
	
	printf("Interesting code\n");
	function1(); 
	function2();
}
