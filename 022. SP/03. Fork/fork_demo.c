#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 

int main(void){
    pid_t pid; 

    pid = fork(); 
    if(pid == -1){
        fprintf(stderr, "fork:%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    if(pid == 0){
        printf("Child Process:pid=%d, ppid=%d\n", getpid(), getppid()); 

    }else{
        printf("Parent Process:pid=%d, ppid=%d\n", getpid(), getppid()); 
    }

    printf("Executed by process with pid=%d\n", getpid()); 
    exit(EXIT_SUCCESS); 
}
