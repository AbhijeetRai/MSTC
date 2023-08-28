#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <pthread.h>

int sum = 0;
#define NR_THREADS 4
#define CHUNK_SIZE 25

pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER;

void* compute_sum(void *args);

typedef struct input { 
	int* array;
	int start_index; 
	int end_index;
}input;

int main(void) {
	
	int* array = (int*)malloc(sizeof(int) * 100); 
	for(int i = 0; i <= 99; i++)
		array[i] = i; 
		
	pthread_t* id_arr = (pthread_t*)malloc(sizeof(pthread_t) * NR_THREADS);
	input* 	input_arr = (input*)malloc(sizeof(input) * NR_THREADS);

	for(int i = 0; i < NR_THREADS; i++) {
		input_arr[i].array = array;
		input_arr[i].start_index = CHUNK_SIZE * i; 
		input_arr[i].end_index = (CHUNK_SIZE * (i + 1)) - 1;
		pthread_create(id_arr + i, NULL, compute_sum, input_arr + i);
	}
	
	for(int i = 0; i < NR_THREADS; i++)
		pthread_join(id_arr[i], NULL);
	
	/*sum of all the integers from 0 to 99 is 4950*/
	assert(sum == 4950);
	
	printf("sum=%d\n", sum);

	free(input_arr);
	input_arr = 0; 
	free(id_arr); 
	id_arr = 0;
	free(array);
	array = 0;

	return (0);
}

void* compute_sum(void* args) {
	
	int i, tmp_sum = 0;
	input* data=(input*)args;

	for(i = data->start_index; i <= data->end_index; i++)
		tmp_sum += data->array[i];

	pthread_mutex_lock(&mutex_lock);
	sum += tmp_sum;
	pthread_mutex_unlock(&mutex_lock);

}
