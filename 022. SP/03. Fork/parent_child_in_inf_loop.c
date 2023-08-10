#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 

#define TRUE                1 
#define MAX_SLEEP_DURATION  4

void child_code(void); 
void parent_code(void); 

int main(void){
    pid_t pid; 

    pid = fork(); 
    if(pid == -1){
        fprintf(stderr, "fork:%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    if(pid == 0){
        child_code(); 
    }else{
        parent_code(); 
    }

    exit(EXIT_SUCCESS); 
}

void child_code(void){
    while(TRUE){
        printf("CHILD:PID%d, CHILD:ppid:%d\n", getpid(), getppid()); 
        sleep(30); 
    }
}

void parent_code(void){
    while(TRUE){
        printf("PARENT:PID:%d, PAERNT:ppid:%d\n", getpid(), getppid()); 
        sleep(rand() % MAX_SLEEP_DURATION); 
    }
}
