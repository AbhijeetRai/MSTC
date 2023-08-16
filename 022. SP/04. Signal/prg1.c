/**
 * Signal system call can be used to set disposition for a system call 
 * Kill system call can be used to send signal to a process 
 */

extern int printf(const char*, ...); 
#include <unistd.h>
#include <signal.h>

void handler(int signum);

int main(void) {
		
	sleep(10);

	//both signals handled with same function, not recommended but possible
	signal(SIGINT, handler);	//ctrl + c 
	signal(SIGQUIT, handler);	//ctrl + backslash	
	
	//ctrl + z sends signal SIGSTOP which just marks process unschedulable, does not kill it 
	//not ideal to use	

	while(1) { 
		sleep(2); 
		printf("Infinite loop || Process ID: %d\n", getpid());
	}
}

void handler(int signum) {
	
	if(signum == SIGINT)
		printf("SIGINT: Currently received signal is %d\n", signum);
	else 
		printf("SIGQUIT: Currently received signal is %d\n", signum);
}
