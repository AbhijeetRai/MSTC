#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <signal.h>
#include <unistd.h> 

#define TRUE 			1
#define MAX_SLEEP_DURATION	4 
#define ASCII_CAP_START		65 
#define NR_ASCII_CAPS		26 

void sigint_handler(int signum); 

int main(void) {
	pid_t pid; 
	
	signal(SIGINT, sigint_handler); 
	pid=fork(); 

	if(pid == 0) {
		signal(SIGINT, sigint_handler); 
		while(TRUE) {
			printf("Child: Char: %c\n", (char)(ASCII_CAP_START + rand() % NR_ASCII_CAPS));
		}
	} else {
		while(TRUE) {
			kill(pid, SIGSTOP);
			sleep(2 + rand() % MAX_SLEEP_DURATION); 
			kill(pid, SIGCONT); 
			sleep(rand() % MAX_SLEEP_DURATION); 
		}
	}
}

void sigint_handler(int signum) {
	
	printf("CTRL + C pressed, exiting successfully\n");
	exit(EXIT_SUCCESS);
}
