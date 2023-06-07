#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


#define month_name_length   16
#define number_of_quarters  4 
#define number_of_months    3


typedef struct report {

    char month[month_name_length];
    long long profit_in_inr;
}report;


int var = 0;
char* months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};


void create_array(report*** ppptr) {

    
    report** pointer_to_report_pointer_array = 0;
    pointer_to_report_pointer_array = (report**)malloc(sizeof(report*) * number_of_quarters);

    if(pointer_to_report_pointer_array == 0) {
        puts("fatal: malloc failed: out of memory: array of report pointer not created\n");
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < number_of_quarters; i++) {
        *(pointer_to_report_pointer_array + i) = (report*)malloc(sizeof(report) * number_of_months);
        if(pointer_to_report_pointer_array[i] == 0) {
            puts("fatal: malloc failed: out of memory: report array not created\n");
            exit(EXIT_FAILURE);
        } 
    }

    for(int i = 0; i < number_of_quarters; i++) {
        report* pointer = *(pointer_to_report_pointer_array + i);

        for(int j = 0; j < number_of_months; j++) {

            strncpy(pointer[j].month, months[var], 4);
            (*(pointer + j)).profit_in_inr = ((i + j) + 1) * 100;
            var += 1;
        }
    }

    *ppptr = pointer_to_report_pointer_array;
}

void show_array(report** pointer_to_report_pointer_array) {

    for(int i = 0; i < number_of_quarters; i++) {
        report* pointer = *(pointer_to_report_pointer_array + i);
        for(int j = 0; j < number_of_months; j++)
            printf("%s %lld\n", pointer[j].month, pointer[j].profit_in_inr);
    }
}

void free_array(report*** ppptr) {

    report** pointer_to_report_pointer_array =  *ppptr; 

    for(int i = 0; i < number_of_quarters; i++) {
        free( *(pointer_to_report_pointer_array + i) );
        pointer_to_report_pointer_array[i] = 0;
    }

    free(*ppptr);
    *ppptr = 0;
}

int main(void) {

    report** pointer_to_report_pointer_array = 0;

    create_array(&pointer_to_report_pointer_array);
    show_array(pointer_to_report_pointer_array);
    free_array(&pointer_to_report_pointer_array);

    return 0;
}