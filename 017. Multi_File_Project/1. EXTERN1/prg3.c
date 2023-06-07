#include <stdio.h>

/*
    ALL OF THE FOLLOWING STATEMENTS ARE 
    PURELY DATA DECLARATER STATEMENTS WHICH 
    DECLARE TYPE OF GLOBAL VARIABLE DEFINED 
    IN THE OTHER FILE
*/

//This struct must be declared again
struct Date {
    int day; 
    int month; 
    int year;
};

extern char g_char;
extern int g_num; 
extern float g_fnum; 
extern int g_arr[5];
extern struct Date g_date_instance;

void print_data(void) {
    int i;

    printf("g_char = %c g_num = %d g_fnum = %.2f\n", 
        g_char, g_num, g_fnum);

    for(i = 0; i < 5; i++)
        printf("%d ", g_arr[i]);
    printf("\n");

    printf("%d-%d-%d\n",    g_date_instance.day, 
                            g_date_instance.month,
                            g_date_instance.year);
}