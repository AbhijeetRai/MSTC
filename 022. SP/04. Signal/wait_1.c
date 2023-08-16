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

void analyse_exit_status(int exit_status); 

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
        sys_ret = execvp(ls_basename, ls_argv); 
        if(sys_ret == FAIL)
            ERROR("exevp:%s\n", strerror(errno)); 
    }else{
        pid = wait(&exit_status); 
        analyse_exit_status(exit_status); 
    }

    exit(EXIT_SUCCESS); 
}

void analyse_exit_status(int exit_status){
    
    signed char return_val; 
    int term_signal_number; 
    int stop_singal_number; 

    if(WIFEXITED(exit_status))
        puts("Child process terminated normally"); 
    
    if(WIFEXITED(exit_status)){
        return_val = WEXITSTATUS(exit_status);
        printf("Return value of a child process:%hhd\n", return_val); 
    }

    if(WIFSIGNALED(exit_status))
        puts("Child process terminated abnormally"); 

    if(WIFSIGNALED(exit_status)){
        term_signal_number = WTERMSIG(exit_status); 
        printf("Abnormal termination of process due to singal number:%d\n", term_signal_number); 

        if(WCOREDUMP(exit_status))
            puts("Child process has terminated abnormally and has produced a core dump"); 
    }

    if(WIFSTOPPED(exit_status)){
        stop_singal_number = WSTOPSIG(exit_status); 
        printf("Child process had been stopped by signal %d\n", stop_singal_number);        
    }

    if(WIFCONTINUED(exit_status))
        puts("Child process execution was resumed by SIGCONT"); 
}