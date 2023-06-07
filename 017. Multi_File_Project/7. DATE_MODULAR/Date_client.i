#line 1 "Date_client.c"
#line 1 "C:\\MSTC\\017. Multi_File_Project\\7. DATE_MODULAR\\Date.h"









typedef int day_t; 
typedef int month_t; 
typedef int year_t; 
typedef int status_t; 
typedef struct Date Date_t;

struct Date {
    day_t day; 
    month_t month; 
    year_t year;
};

extern Date_t* create_date(day_t init_day, month_t init_month, year_t init_year);
extern day_t get_day(const Date_t* p_date); 
extern month_t get_month(const Date_t* p_date);
extern year_t get_year(const Date_t* p_date);
extern status_t set_day(Date_t* p_date, day_t new_day);
extern status_t set_month(Date_t* p_date, month_t new_month);
extern status_t set_year(Date_t* p_date, year_t new_year);
extern void show_date(const Date_t* p_date);
extern status_t destroy_date(Date_t** pp_date);

static status_t is_date_valid(day_t day, month_t month, year_t year);

#line 35 "C:\\MSTC\\017. Multi_File_Project\\7. DATE_MODULAR\\Date.h"
#line 2 "Date_client.c"


#line 5 "Date_client.c"


int main(void)
{
    Date_t* p_date = ((void*)0);  

    p_date = create_date(15, 8, 1947); 
    show_date(p_date); 
    set_day(p_date, 26); 
    set_month(p_date, 1); 
    set_year(p_date, 1950); 
    show_date(p_date); 

    return (0); 
}
