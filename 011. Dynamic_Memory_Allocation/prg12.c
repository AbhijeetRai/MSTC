#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <assert.h> 


#define no_of_years                 5
#define no_of_quarters              4
#define no_of_months_in_a_quarter   3


typedef struct Report {
    int profit;
    char month[4];
    int year;
}Report;


char* months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int years[] = {2020, 2021, 2022, 2023, 2024};


Report*** create_array();
void show_array(Report*** master_pointer);
void init_array(Report*** master_pointer);
void free_array(Report**** pointer_to_master_pointer);


int main(int argc, char* argv[]) {

    Report*** master_pointer = create_array();
    init_array(master_pointer);
    show_array(master_pointer);
    free_array(&master_pointer);

    assert(master_pointer == 0);
}


Report*** create_array() {

    Report*** master_pointer = (Report***)malloc(sizeof(Report**) * no_of_years);
    assert(master_pointer != 0);
    memset(master_pointer, 0, sizeof(Report**) * no_of_years);

    for(int i = 0; i < no_of_years; i++) {
        master_pointer[i] = (Report**)malloc(sizeof(Report*) * no_of_quarters);
        assert(master_pointer[i] != 0);
        memset(master_pointer[i], 0, sizeof(Report*) * no_of_quarters);

        for(int j = 0; j < no_of_quarters; j++) {
            master_pointer[i][j] = (Report*)malloc(sizeof(Report) * no_of_months_in_a_quarter);
            assert(master_pointer[i][j] != 0); 
            memset(master_pointer[i][j], 0, (sizeof(Report) * no_of_months_in_a_quarter));
        }
    }

    return master_pointer;
} 

void show_array(Report*** master_pointer) {

    for(int i = 0; i < no_of_years; i++) {
        for(int j = 0; j < no_of_quarters; j++) {
            for(int k = 0; k < no_of_months_in_a_quarter; k++) 
                printf("%d %s: profit =  %d\n", (master_pointer[i][j] + k) -> year, (master_pointer[i][j] + k) -> month, (master_pointer[i][j][k]).profit);
        }
        printf("\n\n");
    }
}

void init_array(Report*** master_pointer) {

    for(int i = 0; i < no_of_years; i++) {
        for(int j = 0; j < no_of_quarters; j++) {
            for(int k = 0; k < no_of_months_in_a_quarter; k++) {
                (master_pointer[i][j] + k) -> profit = (i + j + k) * 100;
                strncpy( (master_pointer[i][j] + k) -> month, months[3 * j + k], 4); 
                (master_pointer[i][j] + k) -> year  = years[i];
            }
        }
    }
}

void free_array(Report**** pointer_to_master_pointer) {
    
    Report*** master_pointer = *pointer_to_master_pointer;

    for(int i = 0; i < no_of_years; i++) 
        for(int j = 0; j < no_of_quarters; j++) {
            free(master_pointer[i][j]);
            master_pointer[i][j] = 0;
        }
            

    free(*pointer_to_master_pointer);
    *pointer_to_master_pointer = 0;
}