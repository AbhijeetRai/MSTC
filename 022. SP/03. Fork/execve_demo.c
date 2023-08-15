/**
 * Here we will create child process from a parent using fork 
 * And child process will call execve to load and run an executable in ram
 * Note: Execve is default loader of OS, used to load executables on ram 
 
 * When child calls execve, child's entire virtual address space is replaced by executable passed in execve 
 * Hence child is not generally executed further than execve. 
 * If it does, execve has failed to load executable and it is error

 * Here wait system is used to collect exit status of child. But ls executbale replaces child 
 * Hence parent will see ls as child and collect its exit status and wait until ls is terminated
 */

#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[]) {
	
	//terminated by NULL
	char* ls_command_line[] = {"ls", "-l", "/", NULL};
	int pid, exit_status, sys_ret; 

	pid = fork();
	
	if(pid == 0) {	
		//first argument is full path of executable to be loaded
		sys_ret = execve("/bin/ls", ls_command_line, envp);
		
		//ideally child gets replaced after execve invokation and lines below should not be executed
	 	if(sys_ret == -1){
            		exit(EXIT_FAILURE);
		}
 
	} else {
		wait(&exit_status); 
		puts("Parent terminated");
	}
	
	return (0);
}
