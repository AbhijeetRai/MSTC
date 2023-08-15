#include <stdio.h>
#include <unistd.h>

/**
 * Demo of time sharing os
 */

void child() {
	
	while(1) {
		sleep(4);
		printf("CHILD: pid(): %d || ppid() %d\n", getpid(), getppid());
	}
}

void parent() {
	
	while(1) {
		sleep(2);
		printf("PARENT: pid(): %d || ppid() %d\n", getpid(), getppid());
	}
}

int main(void) {
	
	pid_t pid; 
	
	pid = fork();
	
	if(pid == 0)
		child(); 
	else 
		parent();
}

