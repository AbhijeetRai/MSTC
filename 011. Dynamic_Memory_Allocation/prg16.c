#include <stdio.h> 
#include <stdlib.h> 


typedef long long int llint;


typedef struct vector {

    unsigned long long int length_of_vector;
    llint* array_ptr;
}vector;


vector* get_vector();
int append_vector(vector* vec_ptr, llint data_to_append); 
void show_vector(vector* vec_ptr);
void destroy_vector(vector** ptr_to_vec_ptr); 


#define SUCCESS 1

int main(void) {

    vector* vec_ptr = get_vector();
    
    append_vector(vec_ptr, 10);
    append_vector(vec_ptr, 20);
    append_vector(vec_ptr, 30);
    append_vector(vec_ptr, 40);
    append_vector(vec_ptr, 50);

    show_vector(vec_ptr);

    destroy_vector(&vec_ptr);

    exit(EXIT_SUCCESS);
}

vector* get_vector() {

    vector* vec_ptr = NULL; 
    vec_ptr = (vector*)calloc(1, sizeof(vector));

    if(vec_ptr == NULL) {
        printf("fatal:calloc:out of memory\n");
        exit(EXIT_FAILURE);
    }

    vec_ptr -> length_of_vector = 0; 
    vec_ptr -> array_ptr = NULL;

    return vec_ptr;
}

int append_vector(vector* vec_ptr, llint data_to_append) {

    vec_ptr -> length_of_vector += 1;
    vec_ptr -> array_ptr = (llint*)realloc(vec_ptr -> array_ptr, sizeof(llint) * (vec_ptr -> length_of_vector));
    (vec_ptr -> array_ptr)[vec_ptr -> length_of_vector - 1] = data_to_append;
    return SUCCESS;
}

void show_vector(vector* vec_ptr) {

    unsigned long long int length_of_vector = vec_ptr -> length_of_vector;
    
    for(unsigned long long int i = 0; i < length_of_vector; i++)
        printf("%lld ", (vec_ptr -> array_ptr)[i]);
    printf("\n");
}

void destroy_vector(vector** ptr_to_vec_ptr) {

    free((*ptr_to_vec_ptr) -> array_ptr);
    (*ptr_to_vec_ptr) -> array_ptr = NULL;
    (*ptr_to_vec_ptr) -> length_of_vector = 0; 

    free(*ptr_to_vec_ptr);
    *ptr_to_vec_ptr = NULL;
}

