#include <stdio.h> 
#include <stdlib.h> 

struct Date {
    int day, month, year;
};

void get_date(struct Date** pptr) {

    struct Date* pDate = 0; 
    int day, month, year; 

    printf("Enter day:");
    scanf("%d", &day); 

    printf("Enter month:");
    scanf("%d", &month);

    printf("Enter year:"); 
    scanf("%d", &year);

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == 0) {
        puts("Error in allocating memory"); 
        exit(-1);
    }

    pDate -> day = day; 
    pDate -> month = month; 
    pDate -> year = year; 

    *pptr = pDate;
}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
}

void release_date(struct Date** ppDate)
{
    free(*ppDate); 
    *ppDate = 0; 
}

int main(void) {

    struct Date* pDate = 0;
    get_date(&pDate);
    show_date(pDate); 
    release_date(&pDate);
    return (0);
}