#include <stdio.h> 

    char c1; 
    unsigned char uc1; 

    short s_num; 
    unsigned short us_num; 

    int i_num; 
    unsigned int ui_num; 

    long l_num; 
    unsigned long ul_num; 

    long long ll_num; 
    unsigned long long ull_num; 

    float f; 
    double d; 
    long double lng_d; 

    //Pointers
    char* p_char; 
    unsigned char* p_uchar; 

    short* p_short; 
    unsigned short* p_ushort; 

    int* p_int; 
    unsigned int* p_uint; 

    long* p_lng; 
    unsigned long* p_ulng; 

    long long* p_llng; 
    unsigned long long* p_ullng; 

    float* p_float; 
    double* p_dbl; 
    long double* p_lng_dbl;

int main(void) {

    
    p_char = &c1; 
    p_uchar = &uc1; 

    p_short = &s_num; 
    p_ushort = &us_num; 

    p_int = &i_num; 
    p_uint = &ui_num; 

    p_lng = &l_num;
    p_ulng = &ll_num;

    p_llng = &ll_num;
    p_ullng = &ull_num;

    p_float = &f; 
    p_dbl = &d; 
    p_lng_dbl = &lng_d;

    return 0;
}