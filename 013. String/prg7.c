#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

typedef char** ArrayListOfStrings;

#define SUCCESS 1

unsigned long long int length_of_list = 0;


ArrayListOfStrings get_list();
int add_string(ArrayListOfStrings* list_ptr, char* string_to_add); 
void show_list(ArrayListOfStrings list);
signed long long int get_index(char* string_to_find, ArrayListOfStrings list);
int compare_strings(char* string1, char* string2); 
int get_length(char* string); 


int main(void) {

    ArrayListOfStrings list = get_list();
    
    add_string(&list, "Charles Petzold");
    add_string(&list, "William Stallings");
    add_string(&list, "Donald Knuth");

    char* array[] = {"Mark Lutz", "Kathy Sierra", "Cormen"};
    add_all(array, 3, &list);  
    show_list(list); 

    return 0;
}

ArrayListOfStrings get_list() {

    ArrayListOfStrings list = (char**)malloc(sizeof(char*));
    if(list == NULL) {
        printf("fatal: out of memory");
        exit(EXIT_FAILURE);
    }
    return list;
}

int add_string(ArrayListOfStrings* list_ptr, char* string_to_add) {

    length_of_list += 1;
    ArrayListOfStrings list = *list_ptr;
    list = realloc(list, length_of_list * sizeof(char*));
    list[length_of_list - 1] = string_to_add;
    
    /*
        Realloc may change the address pointed by the pointer list, when memory size is increased. 
        Depending on, If the memory location in front of already pointed memory is mapped or unmapped 
        If memory location, in front of already pointed memory is mapped, 
        address pointed with pointer(list here) is not changed by realloc
        If memory location, in front of already pointed memory is unmapped, 
        address pointed with pointer(list here) is changed by realloc. 

        Hence if address pointed by list is changed, it needs to be updated in the main function 
        (list variable in stack frame of the main). Hence, using call by reference here for list
    */
    *list_ptr = list;
    return SUCCESS;
}

/*
    Here we are performing no write operation, hence address pointed by list 
    will not be updated, hence using call by value mechanism
*/
void show_list(ArrayListOfStrings list) {

    for(unsigned long long int i = 0; i < length_of_list; i++)
        printf("%s, ", list[i]);
    printf("\n");
}

signed long long int get_index(char* string_to_find, ArrayListOfStrings list) {

    signed long long int index = -1;
    for(unsigned long long int i = 0; i < length_of_list; i++)
        if(compare_strings(list[i], string_to_find))
            index = i;
    return index;
}

int compare_strings(char* string1, char* string2) {
    
    if(get_length(string1) != get_length(string2))
        return 0; 

    int flag = 1;
    unsigned long long int i = 0;
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

    unsigned long long int i = 0; 
    while(string[i] != '\0') 
        i += 1; 
    
    return i;
}

int add_all(char** pointer_to_char_pointer_array, int array_length, ArrayListOfStrings* list_ptr) {

    for(int i = 0; i < array_length; i++)
        add_string(list_ptr, pointer_to_char_pointer_array[i]);
    return SUCCESS;
}