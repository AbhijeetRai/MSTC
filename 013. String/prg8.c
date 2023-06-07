#include <stdio.h> 
#include <stdlib.h> 

int string_length(char* string);
void string_copy_N_char(char* source, char** dest_ptr, int N);
int split_string(char* source, char* seperator, char*** string_array_pointer);
char* join(char** array_to_be_joined, int N, char* joiner);
int string_length(char* string);

int main(void) {


    /*char* string1 = "/23/03/2021/";

    int size = 0;
    char** string_array = NULL;
    size = split_string(string1, "/", &string_array);
    
    for(int i = 0; i < size; i++) {
        char* sep = NULL;
        if(i != size - 1) 
            sep = "/";
        else 
            sep = "";
        printf("%s %d\n", string_array[i], i);
    }*/

    char* array_to_be_joined[] = {"Mr", "Abhi", "RN", "Rai",};
    char* joined_string = join(array_to_be_joined, 4, "###");
}

int string_length(char* string) {

    int i = 0; 
    while(string[i] != '\0') 
        i += 1; 
    
    return i + 1;
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

/*
* Function: split_string
* -----------------------
* splits the string based on seperator: E.g: "/" or "-" 
*
* source: string which is to be splitted 
* seperator: seperator on which to split the source string 
* string_array_pointer: pointer to char**(pointer of array of strings), return value as paramter, returns array of spliited string
*
* returns: number of splitted strings in the source string
*/
int split_string(char* source, char* seperator, char*** string_array_pointer) {

    char sep = seperator[0];
    int source_length = string_length(source);

    int prev_index = -1; 
    int length = 0;

    char** string_array = NULL;
    int occurance = 0;

    for(int i = 0; i < source_length; i++) {

        if(source[i] == sep) {
            length = i - prev_index;
            char* temp_str = NULL;
            temp_str = (char*)malloc(sizeof(char) * length);
            string_copy_N_char(source + prev_index + 1, &temp_str, length - 1);

            occurance += 1;
            string_array = (char**)realloc(string_array, occurance * sizeof(char*));
            string_array[occurance - 1] = temp_str;

            prev_index = i;
        }
    }

    length = source_length - 1 - prev_index;
    char* temp_str = NULL;
    temp_str = (char*)malloc(sizeof(char) * length);
    string_copy_N_char(source + prev_index + 1, &temp_str, length - 1);

    occurance += 1;
    string_array = (char**)realloc(string_array, occurance * sizeof(char*));
    string_array[occurance - 1] = temp_str;

    *string_array_pointer = string_array;
    return occurance;
}

char* join(char** array_to_be_joined, int N, char* joiner) {

    char* result = NULL;
    int joiner_length = string_length(joiner) - 1;
    int str_len = 0;
    int prev_length = 0;

    for(int i = 0; i < N - 1; i++) {
        str_len = string_length(array_to_be_joined[i]) - 1;
        result = (char*)realloc(result, sizeof(char) * (prev_length + str_len + joiner_length));

        int j = 0;
        int k = 0;

        for(j = prev_length; j < str_len; j++)  {
            result[j] = array_to_be_joined[i][k];
            k += 1;
        }

        for(int l = 0; l < joiner_length; l++)
            result[j] = joiner[l]; 
            j++;

        printf("%s\n", result);
        prev_length = (prev_length + str_len + joiner_length);
    }
    printf("%s", result);
    return result;
}

/**
 * Yes, true, 90%, Sir, instead of dooing "for under for"
 *          for i in iterable: 
 *              for j in iterable 
 *                  index[i + 1] with some j logic 
 * 
 * But rather comforatable with 
 *  for i in iterable: 
 *      for j in iterable 
 *          logic_function(i, j)
 * 
 * It allows my brain to work inderpendently with logic, 
 * Small problem at a time
*/