extern void print_data(void); 

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

int main(void) {
    int i;

    print_data();
    g_char = 'X';
    g_num = -4500;
    g_fnum = 6.28;
    for(i = 0; i < 5; i++)
        g_arr[i] = (i + 1) * 1500;
    g_date_instance.day = 25;
    g_date_instance.month = 4; 
    g_date_instance.year  = 2023;
    print_data();

    return (0);
}