#include "lib.h" 

static struct student s_lib_copy;

void set(struct student* p_student) {
    if(p_student->mask & ST_ALL) {
        memcpy(&s_lib_copy.iroll, &p_student->iroll, 
            p_student->size - (unsigned long long)OFFSET(struct student, iroll));
        return; 
    }

    if(p_student->mask & ST_ROLL)
        s_lib_copy.iroll = p_student->iroll;

    if(p_student->mask & ST_ATTND)
        s_lib_copy.iattnd = p_student->iattnd;

    if(p_student->mask & ST_MARKS)
        s_lib_copy.imarks = p_student->imarks;
}

void get(struct student* p_student) {
    if(p_student->mask & ST_ALL) {
        memcpy(&p_student->iroll, &s_lib_copy.iroll, 
            p_student->size - (unsigned long long)OFFSET(struct student, iroll));
        return; 
    }

    if(p_student->mask & ST_ROLL)
        p_student->iroll = s_lib_copy.iroll;

    if(p_student->mask & ST_ATTND)
        p_student->iattnd = s_lib_copy.iattnd;

    if(p_student->mask & ST_MARKS)
        p_student->imarks = s_lib_copy.imarks;
}

void show(struct student* p_student) {
    if(p_student->mask & ST_ALL) {
        printf("roll = %d, attnd = %d, marks = %d\n",
             p_student->iroll, p_student->iattnd, p_student->imarks);
    }

    if(p_student->mask & ST_ROLL)
        printf("roll = %d\n", p_student->iroll); 
    if(p_student->mask & ST_ATTND)
        printf("attnd = %d\n", p_student->iattnd); 
    if(p_student->mask & ST_MARKS)
        printf("marks = %d\n", p_student->imarks); 
    
}