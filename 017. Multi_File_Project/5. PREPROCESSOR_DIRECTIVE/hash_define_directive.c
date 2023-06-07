//USe command: cl /P hash_define_directive.c
//to see the preprocessed file

/*
 * Using #define directive to create symbolic constants
*/

/*
int a[5];

struct Date {
    int day, month, year;
}epoch_date = {1, 1, 1970};
*/

/*
    Principle: Magical (= written in program without any additional explanation)
    constants make code UNREADABLE TO OTHER PROGRAMMERS AND TO THE PROGRAMMER 
    HIMSELF/HERSELF after some time.

    We can assign a label so to speak with constant. Label can be an English word 
    and therefore will make code more readbale;

    We could have used vaiable names 
    int arr_size = 5; 

    But it will cost memory. Therefore, we make use of preprocessor directive 
    #define 
*/

/*
    SYNTAX 
    #define     NAME    REPLACEMENT_STR 

    Preprocessor does two tasks: 
        1) When #define statement is encountered it understand that its a command 
        given by programmer to it. And the command means to define PREPROCESSIR SYMBOL 
        'NAME' with its definition 'REPLACEMENT_STR'. Preprocessor takes note of this definition

        2) Replace name with REPLACEMENT_STR
*/

#define ARR_SIZE    5 

#define EPOCH_DAY   1 
#define EPOCH_MONTH 1 
#define EPOCH_YEAR  1970 

struct Date {
    int day, month, year;
} epoch_date = {EPOCH_DAY, EPOCH_MONTH, EPOCH_YEAR};

#define RANDOM  XYZ\
                1\
                346535353\
                PQR\
                LOL

int main(void) {

    RANDOM;
    int arr[ARR_SIZE];
}