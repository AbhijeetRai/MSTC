#include <stdio.h>
#include <unistd.h>

/**
 * The fork system call is responsible for creating a child process. 
 * Process which calls fork becomes the parent process
 * Child copies virtual address space of parent 

 * Child's process id is returned to parent and 0 is returned to child process by fork 
 * to indicate you (child) have been successfully created
 */

int main(void) {
	
	pid_t pid; 
	
	pid = fork();
	
	if(pid == 0) 
		printf("CHILD || CHILD PROCESS ID: %d || CHILD's PARENT PROCESS ID: %d\n", getpid(), getppid()); 
	else {	
		sleep(2);
		printf("PARENT|| PID RETURNED TO PARENT: %d || PARENT PROCESS ID: %d\n", pid, getpid());	
	}
}
