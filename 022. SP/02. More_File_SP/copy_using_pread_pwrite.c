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
    int fd_src, fd_dest; 
    ssize_t read_bytes, written_bytes; 
    off_t src_offset = 0, dest_offset = 0; 

    assert(argc == 3); 

    fd_src = open(argv[1], O_RDONLY); 
    assert(fd_src != -1); 

    fd_dest = open(argv[2], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    assert(fd_dest != -1); 

    while((read_bytes = pread(fd_src, buffer, BUFFER_SIZE, src_offset)) > 0){
        src_offset += read_bytes; 
        written_bytes = pwrite(fd_dest, buffer, read_bytes, dest_offset); 
        assert(written_bytes == read_bytes); 
        dest_offset += written_bytes; 
    }
    assert(read_bytes != -1); 

    assert(close(fd_src) != -1); 
    assert(close(fd_dest) != -1); 

    return (EXIT_SUCCESS); 
}