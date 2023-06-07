#include <stdio.h>
#include <stdlib.h> 


char* get_array(int* size_ptr, int toggle_case);
void show_array(const char* message, char* array, int size);
void get_substring(char* string, int str_len, char** substring_ptr, int* substring_len_ptr); 
int find_char_occurance(char* string, int size, int index, char value);
void create_substring(char* string, int str_len, char* substring); 


int main(void) {

    int N1 = 0;
    char* array1 = get_array(&N1, 0); 
    show_array("String: ", array1, N1);

    char* array2 = NULL; 
    int N2 = 0;
    get_substring(array1, N1, &array2, &N2);
    show_array("Substring: ", array2, N2);

    printf("\n");

    array1 = get_array(&N1, 1); 
    show_array("String: ", array1, N1);

    get_substring(array1, N1, &array2, &N2);
    show_array("Substring: ", array2, N2);
    
    return 0;
}

char* get_array(int* size_ptr, int toggle_case) {

    int N1 = 0; 
    printf("Enter length of string: "); 
    scanf("%d", &N1); 

    if(N1 <= 1) {
        printf("String length must be greater than 1\n"); 
        _getch(); 
        exit(EXIT_FAILURE);
    }

    char* array1 = (char*)malloc(sizeof(char) * (N1 + 1));

    if(array1 == NULL) {
        printf("fatal: malloc: out of memory\n");
        exit(EXIT_FAILURE);
    }

    int flag = 0;
    for(int i = 0; i < N1; i++) {

        if(flag == 0) {
            array1[i] = (rand() % 6) + 65;
            flag = 1 - toggle_case;
        }

        else {
            array1[i] = (rand() % 6) + 97;
            flag = 0;
        }
    }

    array1[N1] = '\0';
    *size_ptr = N1 + 1;
    return array1;
}

void show_array(const char* message, char* array, int size) {

    if(message) 
        printf(message);

    for(int i = 0; i < size; i++) 
        printf("%c", array[i]); 
    printf("\n");
}

int find_char_occurance(char* string, int size, int index, char value) {

    int occurance = 0;

    for(int i = 0; i < size; i++) {
        if(string[i] == value) {
            if(i < index) 
                return 0;
            else 
                occurance += 1;
        }
    }

    //printf("%c %d\n", value, occurance);
    if(occurance > 2) 
        return 1; 
    else 
        return 0;
}

void get_substring(char* string, int str_len, char** substring_ptr, int* substring_len_ptr) {

    int chars_occuring_two_plus_times = 0;         

    for(int i = 0; i < str_len; i++)
        if(find_char_occurance(string, str_len, i, string[i]))
            chars_occuring_two_plus_times += 1;

    //printf("%d\n", chars_occuring_two_plus_times);

    char* substring = (char*)malloc(sizeof(char) * (chars_occuring_two_plus_times + 1));
    substring[chars_occuring_two_plus_times] = '\0';

    create_substring(string, str_len, substring);

    *substring_ptr = substring; 
    *substring_len_ptr = chars_occuring_two_plus_times + 1;
}

void create_substring(char* string, int str_len, char* substring) {

    int input_index = 0; 

    for(int i = 0; i < str_len; i++) 
        if(find_char_occurance(string, str_len, i, string[i])) {
            substring[input_index] = string[i];  
            input_index++;
        }
}