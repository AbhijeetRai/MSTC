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

    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    assert(fd != -1); 

    memset(buffer, 'A', BUFFER_SIZE); 
    written_bytes = write(fd, buffer, BUFFER_SIZE); 
    assert(written_bytes == BUFFER_SIZE); 

    memset(buffer, 'B', BUFFER_SIZE); 
    written_bytes = write(fd, buffer, BUFFER_SIZE); 
    assert(written_bytes == BUFFER_SIZE);     

    off = lseek(fd, 0, SEEK_END); 
    assert(off != -1); 
    printf("CURRENT END = %lu\n", off); 

    off = lseek(fd, BUFFER_SIZE, SEEK_END); 
    assert(off != -1); 
    printf("CURRENT OFFSET = %lu\n", off); 

    written_bytes = write(fd, "#", 1); 
    assert(written_bytes == 1); 


    assert(close(fd) != -1); 
    return (EXIT_SUCCESS); 
}