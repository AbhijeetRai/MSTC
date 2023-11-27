/**
 * Pipe between parent and child is called unnamed pipe 
 * It acts like (share resource or file or pipe) between parent and child 
 * Both parent and child receive two descriptors (total 4) of pipe (acting as file on ram) 
 * between two process. Two Descriptors per process are for reading and writing. Making it 
 * bi-directional for both the processes. It is used for communication between parent and child. 
 * Since it exists as shared resource on RAM, it is called unnamed pipe.  
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <time.h>
#include <sys/types.h> 

#define TRUE			1 
#define CHILD_SLEEP_DURATION	2 
#define BUFFER_SIZE		32 
#define SMALL_ASCII_START 	97 
#define NR_SMALL_ALPHABETS	26 

char r_buffer[BUFFER_SIZE/4], w_buffer[BUFFER_SIZE]; 

int main(void) {
	
	//fd[2]: by copy on write property, both parent and child should get unique fd[2]
	int fd[2], ret, rb, wb; 
	pid_t pid; 
	
	srand(time(0)); 
	
	ret = pipe(fd); 
	if(ret == -1) {
		fprintf(stderr, "pipe:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if((int)pid == -1) {
		fprintf(stderr, "fork:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE);
	}
	
	
	if((int)pid == 0) {
		//close the writing descriptor for child
		if(close(fd[1] == -1)) {
			fprintf(stderr, "close:%s\n", strerror(errno)); 
			exit(EXIT_FAILURE);
		}

		while(TRUE) {
			sleep(CHILD_SLEEP_DURATION);
			memset(r_buffer, (int)'\0', BUFFER_SIZE/4); 
			rb = read(fd[0], r_buffer, BUFFER_SIZE/4);
			if(rb == -1) {
				fprintf(stderr, "read:%s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
			printf("CHILD_READER:%s\n", r_buffer);	
		}
	} else {
		//close reading descriptor for parent, parent will only write
		if(close(fd[0] == -1)) {
			fprintf(stderr, "close:%s\n", strerror(errno)); 
			exit(EXIT_FAILURE);			
		}

		while(TRUE) {
			memset(w_buffer, SMALL_ASCII_START + (rand() % NR_SMALL_ALPHABETS), BUFFER_SIZE);
			wb = write(fd[1], w_buffer, BUFFER_SIZE); 
			if(wb == -1) {
				fprintf(stderr, "write:%s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
	}

	return (EXIT_SUCCESS);
}
