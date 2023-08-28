#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

//Dummy code tp show, dynamically allocating mutex

pthread_mutex_t* p_mu = NULL;

void test(void) {
	
	p_mu = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	if(p_mu == NULL) {
		puts("Error in allocating memory");	
		exit(EXIT_FAILURE);		
	}

	pthread_mutex_init(p_mu, NULL);
	
	pthread_create(); 
	pthread_create(); 

	pthread_join(); 
	pthread_join(); 

	free(p_mu); 
	p_mu = NULL;
}

void* thread_func(void* args) {
	pthread_mutex_lock(p_mu); 
	//CRITICAL REGION 
	pthread_mutex_unlock(p_mu);
}
