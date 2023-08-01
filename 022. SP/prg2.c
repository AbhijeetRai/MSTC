#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
	
	#define BUFFER_SIZE 4096 
	static char buffer[BUFFER_SIZE];
	ssize_t readbytes, writebytes;

	const char* src_path = "/home/ubuntu/MSTC/022. SP/file1.txt";
	const char* dest_path = "/home/ubuntu/MSTC/022. SP/file2.txt";
	
	int src_fd = open(src_path, O_RDONLY | O_CREAT, S_IRWXU); 
	if(src_fd == -1) {
		printf("%s %s\n", src_path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("src_fd = %d\n", src_fd);

	int dest_fd = open(dest_path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if(dest_fd == -1) {
		printf("%s %s\n", dest_path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("dest_fd = %d\n", dest_fd);	

	while(readbytes = read(src_fd, buffer, BUFFER_SIZE)) {
		printf("readbytes = %d\n", readbytes);
		writebytes = write(dest_fd, buffer, readbytes);
		printf("writebytes = %d\n", writebytes);

		//If for some call read and write bytes do not match 
		if(readbytes != writebytes) 
			printf("Read and Written bytes mismatch");
	}
	
	//read returns -1 on error or signal interrupt 
	if(readbytes == -1) {
		printf("read:%s %s\n", src_path, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(close(src_fd) == -1) {
		printf("Error in freeing source file descriptor: %s\n", strerror(errno)); 
		exit(EXIT_FAILURE);
	}	

	if(close(dest_fd) == -1) {
		printf("Error in freeing destination file descriptor: %s\n", strerror(errno)); 
		exit(EXIT_FAILURE);
	}

	return (0);
}
