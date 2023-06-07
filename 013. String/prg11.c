#include <stdio.h> 
#include <stdlib.h> 

void join(char** strings, char** joined_string_ptr, char* joiner, int N);
int length(char* string);

int main(void) {

    char* strings[] = {"Abhi", "Rai", "Pune", "Veritas"};

    char* joined_string;
    join(strings, &joined_string, "##", 4);
    printf("%s\n", joined_string);

    return 0;
}

int length(char* string) {

    int i;
    for(i = 0; string[i] != '\0'; i++)
        ; 

    return i;
}

void join(char** strings, char** joined_string_ptr, char* joiner, int N) {

    char* joined_string = NULL; 
    int prev_length = 0;
    int copy_index = 0;

    int joiner_length = length(joiner);

    int i;
    for(i = 0; i < N-1; i++) {

        int current_length = prev_length + length(strings[i]) + joiner_length;
        joined_string = (char*)realloc(joined_string, sizeof(char) * current_length);

        for(int j = 0; strings[i][j] != '\0'; j++) {
            joined_string[copy_index] = strings[i][j];
            copy_index++;
        }

        for(int j = 0; j < joiner_length; j++) {
            joined_string[copy_index] = joiner[j];
            copy_index++;
        }
        prev_length = current_length;
    }

    int last_string_length = length(strings[i]);
    prev_length = prev_length + last_string_length + 1;

    joined_string = (char*)realloc(joined_string, sizeof(char) * prev_length);

    for(int j = 0; j < last_string_length; j++) {

        joined_string[copy_index] = strings[i][j];
        copy_index++;
    }

    joined_string[copy_index] = '\0';

    *joined_string_ptr = joined_string;
}