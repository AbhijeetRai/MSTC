#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>

struct input_data {
	int ia[5]; 
	double da[5];
};

struct output_data {
	int i_sum; 
	double d_sum;
};

void* compute_thread(void* args);



int main(void) {
	pthread_t thread_id;
	struct input_data* input = NULL;
	struct output_data* output = NULL;
	int i;

	input = (struct input_data*)malloc(sizeof(struct input_data));
	
	for(i = 0; i < 5; i++) {
		input -> ia[i] = (i + 1) * 10; 
		input -> da[i] = ((i + 1) * 100) / 7.0;
	}

	pthread_create(&thread_id, NULL, compute_thread, (void*)input);

	pthread_join(thread_id, (void**)&output);
	printf("%d %.2lf\n", output->i_sum, output->d_sum);

	free(input); 
	input = NULL;

	free(output); 
	output = NULL;

	return(0);
}

void* compute_thread(void* args) {
	
	struct input_data* input = (struct input_data*)args;
	struct output_data* output = NULL;
	int i;


	output = (struct output_data*)malloc(sizeof(struct output_data));
	output -> i_sum = 0; 
	output -> d_sum = 0.0;

	for(i = 0; i < 5; i++) {
		output -> i_sum += input -> ia[i];
		output -> d_sum += input -> da[i];
	}

	return ((void*)output);

}
