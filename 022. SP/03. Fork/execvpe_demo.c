#define _GNU_SOURCE     /* for execvpe */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 

#define ERROR(name, msg) do{\
                                fprintf(stderr, name, msg);\
                                exit(EXIT_FAILURE);\
                            }while(0)
#define FAIL -1

int main(int argc, char* argv[], char* envp[]){
    static char* ls_basename = "ls";
    static char* ls_argv[] = {"ls", "-l", "/", NULL}; 

    pid_t pid;
    int sys_ret; 
    int exit_status; 

    pid = fork(); 
    if(pid == -1){
        fprintf(stderr, "fork:%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    } 

    if(pid == 0){
        sys_ret = execvpe(ls_basename, ls_argv, envp); 
        if(sys_ret == FAIL)
            ERROR("exevpe:%s\n", strerror(errno)); 
    }else{
        wait(&exit_status); 
    }

    exit(EXIT_SUCCESS); 
}