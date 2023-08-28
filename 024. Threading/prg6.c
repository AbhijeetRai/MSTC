#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

#define TRUE 1 

/**
 * Program to show synchronized multithreading
 */

void* common_thread_function(void* args);

int shared_var=0;
pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
	pthread_t tid_1, tid_2; 	
	
	pthread_create(&tid_1, NULL, common_thread_function, NULL); 
	pthread_create(&tid_2, NULL, common_thread_function, NULL);

	pthread_join(tid_1, NULL);
	pthread_join(tid_2, NULL);

	return (0);
}

void* common_thread_function(void* args) {
	
	while(TRUE) {
		pthread_mutex_lock(&mutex_lock);
		++shared_var; 
		printf("Thread ID: %lx||shared_number=%d\n", pthread_self(), shared_var);
		pthread_mutex_unlock(&mutex_lock);
	}	
}
