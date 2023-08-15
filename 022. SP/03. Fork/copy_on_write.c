#include <stdio.h> 
#include <unistd.h> 

/*
 * Child process copies virtual address space of parent: stack, heap, bss, data, rodata and text 
 * They both look at same variable in virtual address space and virtual address space of variable is mapped to same physcial address space of variable 
 
 * Copy on write: Until one process modifies the variable, then virtual address space of variable looks to different physcial address space of variable 
 * Thus, after modification, even virtual address space of variables is same, they point to different variables in physical address space. 
 
 * Physical address space or address is not accessible by our code here hence we get (same) virtual address of variable 
 * But different state 10 and 20 of variable num is persisted shows different physical copies exist
 */

int num = 10;

void parent() {
	while(1) {
		printf("PARENT: num = %d || &num = %llu\n", num, (unsigned long long) &num);
		sleep(2);
	}
}

void child() {
	
	while(1) {
		printf("CHILD: num = %d || &num = %llu\n", num, (unsigned long long) &num);
		sleep(4);
	}
}

int main(void) {
	
	int pid;
	pid = fork();

	if(pid == 0) {
		num = 20;
		child();
	} else {
		parent();
	}
}
