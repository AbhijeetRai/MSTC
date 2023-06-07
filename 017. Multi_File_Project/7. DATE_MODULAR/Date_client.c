#include "Date.h"
#ifndef NULL 
#define NULL ((void*)0) 
#endif 


int main(void)
{
    Date_t* p_date = NULL;  

    p_date = create_date(15, 8, 1947); 
    show_date(p_date); 
    set_day(p_date, 26); 
    set_month(p_date, 1); 
    set_year(p_date, 1950); 
    show_date(p_date); 

    return (0); 
}