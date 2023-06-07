#ifndef _LIB_H 
#define _LIB_H 
#include <stdio.h> 

#define OFFSET(T, x)    (&(((T*)0)->x))

#define ST_ROLL     1
#define ST_ATTND    2 
#define ST_MARKS    4 
#define ST_ALL      8

struct student {
    size_t size; 
    unsigned int mask;

    int iroll;
    int iattnd; 
    int imarks;
};

void get(struct student* p_student);
void set(struct student* p_student);
void show(struct student* p_student);

#endif