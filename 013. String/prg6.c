#include <stdio.h> 
#include <stdlib.h> 

typedef unsigned long long int u64;

u64 string_length(char* string); 
void string_copy(char* source, char* destination); 
char* string_concat(char* string1, char* string2); 
void string_copy_N_char(char* source, char** dest_ptr, int N);

int main(void) {

    char* string1 = "Abhi Rai"; 
    u64 length = string_length(string1);
    
    char* string2 = NULL; 
    string2 = (char*)malloc(sizeof(char) * length);
    if(string2 == NULL) {
        printf("fatal: malloc: memory allocation failed");
        exit(EXIT_FAILURE);
    }
    string_copy(string1, string2);

    char* string3 = "Abhi Rai"; 
    char* string4 = "Lov Rai";
    char* string5 = string_concat(string3, string4);

    char* string6 = "ABHIJEET RAI";
    char* string7 = NULL;
    string_copy_N_char(string6, &string7, 4);
    printf("%s\n", string7);
}

u64 string_length(char* string) {

    u64 i = 0; 
    while(string[i] != '\0') 
        i += 1; 
    
    return i + 1;
}

void string_copy(char* source, char* destination) {

    int i = 0; 
    while(source[i] != '\0') {
        destination[i] = source[i];
        i += 1;
    }
    destination[i] = source[i];
}

char* string_concat(char* string1, char* string2) {

    char* string3 = NULL; 
    u64 string3_length = string_length(string1) + string_length(string2) - 1;
    string3 = (char*)malloc(sizeof(char) * string3_length);
    if(string3 == NULL) {
        printf("fatal: malloc: memory allocation failed");
        exit(EXIT_FAILURE);
    }

    string_copy(string1, string3);
    u64 string1_length = string_length(string1);
    string_copy(string2, string3 + string1_length - 1);

    return string3;
}

void string_copy_N_char(char* source, char** dest_ptr, int N) {

    char* destination = NULL; 
    destination = (char*)malloc(sizeof(char) * N + 1);

    if(destination == NULL) {
        printf("fatal: memory allocation failed"); 
        exit(EXIT_FAILURE);
    }

    int i = 0; 
    while(source[i] != '\0' && i < N) {
        destination[i] = source[i];
        i += 1;
    }

    destination[i] = '\0';
    *dest_ptr = destination;
}