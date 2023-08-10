#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define TRUE 1 
#define FALSE 0 

typedef int flag_t; 

int main(int argc, char* argv[]){
    int ret; 
    flag_t S_flag = FALSE, c_flag = FALSE, o_flag = FALSE; 

    while((ret = getopt(argc, argv, "hvSco:"))){
        switch((char)ret){
            case 'h': 
                break; 
            case 'v': 
                break; 
            case 'S':
                break; 
            case 'c': 
                break; 
            case 'o': 
                break; 
        }
    }

    exit(EXIT_SUCCESS); 
}