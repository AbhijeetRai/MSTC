//compile: gcc prg2.c -lpthread

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h>

void* thread_entry_function(void* args);

int main(void) {
	
	pthread_t thread_id1, thread_id2;
	pthread_create(&thread_id1, NULL, thread_entry_function, NULL);
	pthread_create(&thread_id2, NULL, thread_entry_function, NULL);

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
}

void* thread_entry_function(void* args) {
	
	while(1) {
		printf("Thread_id:%lx\n", pthread_self());
		sleep(2);
	}
}
