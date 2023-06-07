#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

#define STANDARD_STRING_SIZE    64

typedef struct string_vector {

    char** p_string_array;
    int length;
}string_vector;

string_vector* get_string_vector();
void push_back(string_vector* p_string_vector, char* data);
void show_vector(string_vector* p_string_vector);
void destroy_vector(string_vector** pp_string_vector); 
void push_front(string_vector* p_string_vector, char* data);
void push_index(string_vector* p_string_vector, int index, char* data);
void pop_back(string_vector* p_string_vector, char** p_data);
void pop_front(string_vector* p_string_vector, char** p_data);
void pop_index(string_vector* p_string_vector, int index, char** p_data);
char* get_index(string_vector* p_string_vector, int index);
void set_index(string_vector* p_string_vector, int index, char* data);


int main(void) {

    int num = 0;
    char* string_entered_by_user = NULL;
    string_vector* p_string_vector = get_string_vector();

    while(1) {
        
        printf("\nPress [1] to enter string. Press [2] to quit: ");
        scanf("%d", &num);
        if(num == 2)
            break;

        string_entered_by_user = (char*)malloc(sizeof(char) * STANDARD_STRING_SIZE);
        if(string_entered_by_user == NULL) {
            printf("fatal: malloc: out of memory\n");
            exit(EXIT_FAILURE);
        }
        memset(string_entered_by_user, 0, sizeof(char) * STANDARD_STRING_SIZE);
        
        printf("Enter string: ");
        scanf("%s", string_entered_by_user);
        printf("Entered string = %s\n", string_entered_by_user);

        push_back(p_string_vector, string_entered_by_user);
        
        string_entered_by_user = NULL;
    }
    
    set_index(p_string_vector, 1, "Ram"); 
    show_vector(p_string_vector);
    destroy_vector(&p_string_vector);
    assert(p_string_vector == NULL);
}

string_vector* get_string_vector() {

    string_vector* p_string_vector = NULL;
    p_string_vector = (string_vector*)malloc(sizeof(string_vector));

    if(p_string_vector == NULL) {
        printf("fatal: out of memory\n");
        exit(EXIT_FAILURE);
    }
    memset(p_string_vector, 0, sizeof(string_vector));

    p_string_vector -> p_string_array = NULL; 
    p_string_vector -> length = 0; 

    return p_string_vector;
}

void push_back(string_vector* p_string_vector, char* data) {

    p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) * ((p_string_vector -> length) + 1));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed"); 
        exit(EXIT_FAILURE);
    }

    p_string_vector -> p_string_array[p_string_vector -> length] = data;
    p_string_vector -> length = (p_string_vector -> length) + 1;
}

void show_vector(string_vector* p_string_vector) {

    int length = p_string_vector -> length;
    for(int i = 0; i < length; i++) 
        printf("%d:%s ", i, p_string_vector -> p_string_array[i]);
    printf("\n");
}

void destroy_vector(string_vector** pp_string_vector) {

    string_vector* p_string_vector = *pp_string_vector;

    for(int i = 0; i < p_string_vector -> length; i++)
        free(p_string_vector -> p_string_array[i]);

    free(p_string_vector -> p_string_array);
    p_string_vector -> p_string_array = NULL;
    p_string_vector -> length = 0;

    free(p_string_vector); 
    p_string_vector = NULL;

    *pp_string_vector = NULL;
}

void push_front(string_vector* p_string_vector, char* data) {

    p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) *  ((p_string_vector -> length) + 1));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed"); 
        exit(EXIT_FAILURE);
    }

    for(int i = p_string_vector -> length - 1; i >= 0; i--)
        (p_string_vector -> p_string_array)[i + 1] = (p_string_vector -> p_string_array)[i];

    (p_string_vector -> p_string_array)[0] = data;
    p_string_vector -> length = (p_string_vector -> length) + 1;
}

void push_index(string_vector* p_string_vector, int index, char* data) {

    p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) * ((p_string_vector -> length) + 1));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed"); 
        exit(EXIT_FAILURE);
    }

    for(int i = p_string_vector -> length - 1; i >= index; i--)
        (p_string_vector -> p_string_array)[i + 1] = (p_string_vector -> p_string_array)[i];

    (p_string_vector -> p_string_array)[index] = data;
    p_string_vector -> length = (p_string_vector -> length) + 1;
}

void pop_back(string_vector* p_string_vector, char** p_data) {

    *p_data = (p_string_vector -> p_string_array)[(p_string_vector -> length) - 1];
    (p_string_vector -> length) = (p_string_vector -> length) - 1;

     p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) * (p_string_vector -> length));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed to shrink"); 
        exit(EXIT_FAILURE);
    }
}

void pop_front(string_vector* p_string_vector, char** p_data) {

    *p_data = (p_string_vector -> p_string_array)[0];

    for(int i = 1; i < p_string_vector -> length; i++)
        (p_string_vector -> p_string_array)[i - 1] = (p_string_vector -> p_string_array)[i];

    (p_string_vector -> length) = (p_string_vector -> length) - 1;
     p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) * (p_string_vector -> length));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed to shrink"); 
        exit(EXIT_FAILURE);
    }
}

void pop_index(string_vector* p_string_vector, int index, char** p_data) {

    *p_data = (p_string_vector -> p_string_array)[index];

    for(int i = index + 1; i < p_string_vector -> length; i++)
        (p_string_vector -> p_string_array)[i - 1] = (p_string_vector -> p_string_array)[i];

    (p_string_vector -> length) = (p_string_vector -> length) - 1;
     p_string_vector -> p_string_array = (char**)realloc(p_string_vector -> p_string_array, sizeof(char*) * (p_string_vector -> length));

    if(p_string_vector -> p_string_array == NULL) {
        printf("fatal: out of memory: realloc failed to shrink"); 
        exit(EXIT_FAILURE);
    }
}

char* get_index(string_vector* p_string_vector, int index) {

    char* data = (p_string_vector -> p_string_array)[index];
    return data;
}

void set_index(string_vector* p_string_vector, int index, char* data) {

    (p_string_vector -> p_string_array)[index] = data;
}