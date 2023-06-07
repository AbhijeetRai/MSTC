#include <stdio.h> 
#include <stdlib.h>

struct Date {
    int day, month, year;
};

struct Time {

    int hour; 
    int minutes;
    int seconds;
};

int main(void) {

    struct Date date_instance = {02, 01, 2023};
    printf("%d/%d/%d\n", date_instance.day, date_instance.month, date_instance.year);

    struct Date* pointer_to_struct = &date_instance; 
    printf("%d/%d/%d\n", pointer_to_struct -> day, pointer_to_struct -> month, pointer_to_struct -> year);


    (*pointer_to_struct).day = 31;
    (*pointer_to_struct).month = 12; 
    (*pointer_to_struct).year = 2022; 

    printf("%d/%d/%d\n", pointer_to_struct -> day, pointer_to_struct -> month, pointer_to_struct -> year);

    struct Time time_instance = {1, 39, 22}; 
    struct Time* pointer_to_time_instance = &time_instance; 

    printf("%dHH:%dMM:%dSS\n", (*pointer_to_time_instance).hour, (*pointer_to_time_instance).minutes, (*pointer_to_time_instance).seconds);
}