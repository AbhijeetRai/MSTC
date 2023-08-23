/**
 * Output of lscpu shows us: no of sockets, core per socket and thread per core 
 * socket is slot where multiple processor chips can be set 
 * Core per socket means, no of cpu per socket 
 * Thread per core is, how many virtual(logical) threads per cpu
 */

/**
 * Child thread will be executed for 3 seconds. Child thread is terminated post 3 seconds. 
 * Because life of parent is 3 second long only. To let child get executed completely, use 
 * join method 
 */

/**
 * Thread is independent execution segment in same virtual address space of creator process. 
 * Thread has seperate user and kernel stack but common bss, data, rodata, heap, text section 
 * with process
 */


//compile: gcc prg1.c -lpthread

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

void* thread_entry_function(void* args);

int main(void) {
	
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, thread_entry_function, NULL);
	sleep(3);
}

void* thread_entry_function(void* args) {
	
	while(1) {
		puts("Inside thread");
		sleep(1);
	}
}
