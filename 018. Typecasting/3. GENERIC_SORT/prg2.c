#include <stdio.h> 
#include <stdlib.h> 

typedef struct student {
    int roll; 
    double attendance; 
    double percentage;
}student; 

typedef struct book {
    int pages; 
    double price; 
    double edition;
}book;

int sort_with_roll(const student* s1, const student* s2);
int sort_with_pages(const book* b1, const book* b2); 

int main(void) {
    
    int (*compare_student)(const student*, const student*) = NULL; 
    compare_student = sort_with_roll;
    /*
    * compare = sort_with_pages;
    * warning C4113: 'int (__cdecl *)(const book *,const book *)' differs in parameter lists from 'int (__cdecl *)(const student *,const student *)'
    */
    
    //Correct way to compare anything
    int(*compare_anything)(const void*, const void*) = NULL; 
    compare_anything = sort_with_roll;
    compare_anything = sort_with_pages;

    return (0); 
}

int sort_with_roll(const student* s1, const student* s2) {
    if(s1->roll > s2->roll)
        return 1; 
    else 
        return 0;
}

int sort_with_pages(const book* b1, const book* b2) {
    if(b1->pages > b2->pages) 
        return 1; 
    else 
        return 0;
}