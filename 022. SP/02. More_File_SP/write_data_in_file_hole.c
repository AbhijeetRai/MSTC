#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/types.h> 

#define BUFFER_SIZE 4096 

char buffer[BUFFER_SIZE]; 

int main(int argc, char* argv[]){
    int fd; 
    off_t off; 
    ssize_t written_bytes; 

    assert(argc == 2); 

    fd = open(argv[1], O_WRONLY); 
    assert(fd != -1); 

    off = lseek(fd, 2*BUFFER_SIZE, SEEK_SET); 
    assert(off != -1); 
    printf("CURRENT OFFSET = %lu\n", off);

    memset(buffer, 'C', BUFFER_SIZE); 
    written_bytes = write(fd, buffer, BUFFER_SIZE); 
    assert(written_bytes == BUFFER_SIZE); 

    assert(close(fd) != -1); 
    return (EXIT_SUCCESS); 
}