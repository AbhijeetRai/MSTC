#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h>

int num = 100; 

int main(void){
    pid_t pid; 

    pid = fork(); 
    if(pid == -1){
        printf("fork():%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    if(pid == 0){
        printf("CHILD:1:num = %d, &num = %llu\n", num, (unsigned long long)&num); 
        num = 200; 
        printf("CHILD:2:num = %d, &num = %llu\n", num, (unsigned long long)&num); 
    }else{
        sleep(5);
        printf("PARENT:num = %d, &num = %llu\n", num, (unsigned long long)&num);  
    }
    exit(EXIT_SUCCESS); 
}
