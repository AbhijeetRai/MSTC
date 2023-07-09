#include <stdio.h>
#include <stdlib.h> 

struct A {
	char c; 
	short snum; 
	int inum;
};

struct A inA1 = {'A', 100, -100}; 
struct A inA2; 

int main(void) {
		
	inA2.c = inA1.c; 
	inA2.snum = inA1.snum;
	inA2.inum = inA1.inum;

	printf("inA2.c=%c, inA2.snum=%hd, inA2.inum=%d\n", inA2.c, inA2.snum, inA2.inum);	

	exit(0);
}
