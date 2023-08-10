#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main(int argc, char* argv[], char* envp[]){
    static char* ls_path = "/bin/ls"; 
    static char* ls_command_line[] = {"ls", "-l", "/", NULL};
    
    pid_t pid; 
    int exit_status; 
    int sys_ret; 

    pid = fork(); 
    if(pid == -1){
        fprintf(stderr, "fork:%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    } 

    if(pid == 0){
        sys_ret = execve(ls_path, ls_command_line, envp); 
        if(sys_ret == -1){
            fprintf(stderr, "execve:%s\n", strerror(errno)); 
            exit(EXIT_FAILURE); 
        }
    }else{
        wait(&exit_status); 
        puts("Parent Terminating"); 
    }

    exit(EXIT_SUCCESS); 
}