/* Zombie process demo */ 

#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <string.h>  
#include <signal.h> 
#include <unistd.h> 

#define TRUE 1 
#define SLEEP_DURATION 20 

void sigchld_handler(int signum); 
void sigint_handler(int signum); 

int main(void){
    pid_t pid; 

    signal(SIGCHLD, sigchld_handler); 
    puts("PARENT:Death of child signal handler is registered"); 
    pid = fork(); 
    if(pid == -1){
        printf("fork():%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    if(pid == 0){
        printf("CHILD:Printing pid for identification:%d\n", getpid()); 
        exit(EXIT_SUCCESS); 
    }else{
        signal(SIGINT, sigint_handler); 
        printf("Entering in an infinite loop. ctrl + c to exit\n"); 
        while(TRUE)
            ; 
    }

    exit(EXIT_SUCCESS); 
}

void sigchld_handler(int signum){
    puts("Inside death of child handler"); 
    puts("Sleeping for 20 seconds"); 
    puts("The child will be in zombie state until this function returns");
    puts("Therefore sleeping for 20 seconds"); 
    puts("Run $ps ax command to see the child in zombie"); 
    sleep(SLEEP_DURATION); 
}

void sigint_handler(int signum){
    puts("ctrl + C is pressed. Exiting normally"); 
    exit(EXIT_SUCCESS); 
}
