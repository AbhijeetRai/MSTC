#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>


#define SUCCESS 0
#define FAILURE 1


typedef char** STRLIST;
int length_of_list = 0;


STRLIST get_list();
int add_string(char* string_to_add, STRLIST list);
int show_list(STRLIST list);
int get_length(char* string);
int compare_strings(char* string1, char* string2);
int get_index(char* string_to_find, STRLIST list); 
//must take array_length for hard coded arrays, In java, collection to be added, does not send length 
//because collection is dynamically created and length is with source code already unlike here
int add_all(char** pointer_to_char_pointer_array, int array_length, STRLIST list); 


int main(int argc, char* argv[]) {

    STRLIST list1 = get_list();
    
    add_string("Ram", list1);
    add_string("Shyam", list1);
    add_string("Geeta", list1); 
    add_string("Seeta", list1);
    show_list(list1);

    int index = get_index("Geetaa", list1);
    printf("Geetaa index: %d\n", index);

    char* array[] = {"Gopi", "Govind", "Drona-Shishya", "Parth"};    
    add_all(array, 4, list1);
    show_list(list1);

    exit(EXIT_SUCCESS);
}

STRLIST get_list() {

    STRLIST list = (char**)calloc(1, sizeof(char*));
    return list;
}

int add_string(char* string_to_add, STRLIST list) {

    length_of_list += 1;
    list = (char**)realloc(list, sizeof(char*) * length_of_list);
    *(list + length_of_list - 1) = string_to_add;
    return SUCCESS;
}

int show_list(STRLIST list) {

    if(list == 0) 
        return FAILURE;

    for(int i = 0; i < length_of_list; i++)
        printf("%s ", list[i]);
    printf("\n");

    return SUCCESS;
}

int get_index(char* string_to_find, STRLIST list) {

    int index = -1; 
    for(int i = 0; i < length_of_list; i++) 
        if(compare_strings(string_to_find, list[i])) 
            index = i;
    return index;
}

int compare_strings(char* string1, char* string2) {

    if(get_length(string1) != get_length(string2))
        return 0; 

    int flag = 1;
    int i = 0; 

    while(string1[i] != '\0' && string2[i] != '\0') {
        if(string1[i] != string2[i]) {
            flag = 0;
            break;
        }
        i += 1;
    }

    return flag;
}

int get_length(char* string) {

    int i = 0; 
    while(string[i] != '\0') 
        i += 1; 

    return i;
}

int add_all(char** pointer_to_char_pointer_array, int array_length, STRLIST list) {

    for(int i = 0; i < array_length; i++) {
        printf("%s\n", pointer_to_char_pointer_array[i]);
        add_string(pointer_to_char_pointer_array[i], list);
    }
    return SUCCESS;
}