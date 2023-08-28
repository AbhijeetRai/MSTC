#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define TRUE 			1 
#define SLEEP_DURATION		3

void* common_thread_function(void* args); 

int global_var = 10; 
int bss_var;

int main(void) {
	
	pthread_t id1, id2;

	pthread_create(&id1, NULL, common_thread_function, NULL);
	pthread_create(&id2, NULL, common_thread_function, NULL);
	
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	exit(0);
}

void* common_thread_function(void* args) {
	int local_var;
	
	while(TRUE) {
		printf("THREAD ID=%lx &global_var=%p &bss_var=%p &local_var=%p\n", pthread_self(), &global_var, &bss_var, &local_var);
		sleep(SLEEP_DURATION);
	}
}
