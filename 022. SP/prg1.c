#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(void) {
	int fd = 0;
	const char* file1 = "/home/abhijeet/blah.txt";	
	const char* file2 = "/etc/passwd";
	
	fd = open(file1, O_RDONLY);
        if(fd == -1)
                printf("Error to open file: %s\n\
                Error: %s\n\
                File: %s\n\
                Line: %d\n", file1, strerror(errno), __FILE__, __LINE__);

	/*
	O_RDWR: Open for reading and writing, such values defined in fcntl.h
	open: function declared in fcntl.h
	errno: reason of last failed systemcall, present in errno.h
	strerror: declared in string.h
	*/

	fd = open(file2, O_RDWR);
	if(fd == -1)
		printf("Error to open file: %s\n\
		Error: %s\n\
		File: %s\n\
		Line: %d\n", file2, strerror(errno), __FILE__, __LINE__);

	return (EXIT_SUCCESS);
}
