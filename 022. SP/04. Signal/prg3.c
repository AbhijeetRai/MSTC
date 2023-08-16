//Parent receives SIGCHLD signal on termination or stopping of child process 
//Ignored by default unless a disposition is set by programmer

#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum); 

int main(void) {
	int pid = fork();
	
	signal(SIGCHLD, sig_handler);
	
	if(pid == 0) {
		printf("child %d \n", getpid());
		sleep(3);
	} else {
		printf("parent %d\n", getpid());
		sleep(15);
	}
}

/**
 * Sleep is interruptible, a process in sleep state can be woken up with signal 
 * Here child and parent go in sleep for 3 and 15 seconds respectively. 
 * After 3 seconds, child will be terminated and SIGCHLD signal is sent to parent 
 * Parent wakes up before 15 seconds and gets terminated
 */ 

void sig_handler(int signum) {
	
	if(signum == SIGCHLD)
		printf("Child process terminated or stopped\n");
}
