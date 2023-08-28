/**
 * @goal: To demonstrate usage of shared variable without synchronization.
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h>

void* thread_entry_function(void* args);

int shared_number = 10;

int main(void) {
	
	pthread_t thread_id1, thread_id2;
	pthread_create(&thread_id1, NULL, thread_entry_function, NULL);
	pthread_create(&thread_id2, NULL, thread_entry_function, NULL);

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
}

void* thread_entry_function(void* args) {
	
	while(1) {
		shared_number += 1;
		printf("Thread ID: %lx||shared_number=%d\n", pthread_self(), shared_number);
	}
}
