#include <stdio.h> 
#include <stdlib.h> 

#define INDEX_INVALID   -1
#define SUCCESS         1

struct vector_int* create_vector_int(void);
void destroy_vector_int(struct vector_int* p_vec_int);
void push_back(struct vector_int* p_vec_int, int data); 
void show_vector(struct vector_int* p_vec_int, const char* msg); 
void push_front(struct vector_int* p_vec_int, int new_data);
int push_at_index(struct vector_int* p_vec_int, size_t index, int new_data);
int pop_back(struct vector_int* p_vec_int, int* p_back_data); 
int pop_front(struct vector_int* p_vec_int, int* p_back_data);
int pop_index(struct vector_int* p_vec_int, size_t index, int* p_back_data);


struct vector_int {

    int* arr; 
    size_t N;
};

int main(void) {

    struct vector_int* p_vec_int = NULL;
    p_vec_int = create_vector_int(); 

    int num = 0; 
    int choice = 0;

    while(1) {
        printf("Do you want to enter an integer? [1]: Yes, [0]: No:");
        scanf("%d", &choice);
        if(choice != 1) 
            break;
        printf("Enter the value:");
        scanf("%d", &num);
        printf("Entered num = %d\n", num);
        push_back(p_vec_int, num);
    }

    int back_data = 0;
    pop_index(p_vec_int, 1, &back_data);
    printf("back_data = %d\n", back_data);
    show_vector(p_vec_int, "p_vec_int");

    destroy_vector_int(p_vec_int);
    p_vec_int = NULL;
}

struct vector_int* create_vector_int(void) {

    struct vector_int* p_vec_int = NULL; 
    p_vec_int = (struct vector_int*)malloc(sizeof(struct vector_int));

    if(p_vec_int == NULL) {
        printf("fatal:malloc:out of memory"); 
        exit(EXIT_FAILURE);
    }

    p_vec_int -> arr = NULL; 
    p_vec_int -> N = 0;

    return p_vec_int;
}

void push_back(struct vector_int* p_vec_int, int data) {

    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) + 1);
    (p_vec_int -> arr)[p_vec_int -> N] = data;
    (p_vec_int -> N) = (p_vec_int -> N) + 1; 
}

void destroy_vector_int(struct vector_int* p_vec_int) {

    free(p_vec_int -> arr);
    free(p_vec_int);
}

void show_vector(struct vector_int* p_vec_int, const char* msg) {

    if(msg != NULL) 
        puts(msg);

    for(size_t i = 0; i < (p_vec_int -> N); i++)
        printf("%d ", p_vec_int -> arr[i]);
    printf("\n");
}

void push_front(struct vector_int* p_vec_int, int data) {

    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) + 1);
    
    for(int i = p_vec_int -> N-1; i >= 0; i--)
        (p_vec_int -> arr)[i + 1] = (p_vec_int -> arr)[i];

    p_vec_int -> N += 1;
    (p_vec_int ->arr)[0] = data;
}

int push_at_index(struct vector_int* p_vec_int, size_t index, int new_data) {

    if(index < 0 || index >= p_vec_int -> N) 
        return INDEX_INVALID;

    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) + 1);
    for(size_t i = p_vec_int -> N-1; i >= index; i--)
        (p_vec_int -> arr)[i + 1] = (p_vec_int -> arr)[i];

    (p_vec_int -> arr)[index] = new_data;
    p_vec_int -> N += 1;
    return SUCCESS;
}

int pop_back(struct vector_int* p_vec_int, int* p_back_data) {

    *p_back_data = (p_vec_int -> arr)[(p_vec_int -> N) - 1];
    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) - 1);

    p_vec_int -> N = p_vec_int -> N - 1;
    return SUCCESS;
}

int pop_front(struct vector_int* p_vec_int, int* p_back_data) {

    *p_back_data = (p_vec_int -> arr)[0];
    for(size_t i = 1; i < p_vec_int -> N; i++)
        (p_vec_int -> arr)[i - 1] = (p_vec_int -> arr)[i]; 

    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) - 1);
    p_vec_int -> N = p_vec_int -> N - 1;
    return SUCCESS;
}

int pop_index(struct vector_int* p_vec_int, size_t index, int* p_back_data) {

    if(index < 0 || index >= p_vec_int -> N) 
        return INDEX_INVALID;

    *p_back_data = (p_vec_int -> arr)[index];

    for(size_t i = index + 1; i < p_vec_int -> N; i++)
        (p_vec_int -> arr)[i - 1] = (p_vec_int -> arr)[i];

    p_vec_int -> arr = (int*)realloc(p_vec_int -> arr, sizeof(int) * (p_vec_int -> N) - 1);
    p_vec_int -> N = p_vec_int -> N - 1;
    return SUCCESS;
}


