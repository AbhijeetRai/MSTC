#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 


#define N 8 


void allocate_int();
void allocate_float(); 
void allocate_struct(); 
void allocate_another_struct();


typedef struct Date { 
    int day; 
    int month; 
    int year;
}Date;


int main(void) {

    allocate_int();
    allocate_float();
    allocate_struct();
    allocate_another_struct(); 

    return 0;
}

void allocate_int() {

    int* PINT = NULL; 
    PINT = (int*)malloc(sizeof(int) * N); 
    if(PINT == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(int i = 0; i < N; i++) 
        PINT[i] = (i + 1) * 10; 

    for(int i = 0; i < N; i++) 
        printf("%d ", PINT[i]); 
    printf("\n");

    free(PINT); 
    PINT = NULL;
}

void allocate_float() {

    float* p_float = NULL; 
    p_float = (float*)malloc(sizeof(float) * N);
    if(p_float == NULL) {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N; i++)
        p_float[i] = (i + 1) * 10 + 1.1;

    for(int i = 0; i < N; i++)
        printf("%.2f ", p_float[i]); 
    printf("\n"); 

    free(p_float);
    p_float = NULL;
}

void allocate_struct() {

    Date* pDate = NULL; 
    pDate = (Date*)malloc(sizeof(Date) * N);
    if(pDate == NULL) {
        puts("Error in allocating memory\n"); 
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N; i++) {
        pDate[i].day = i + 1; 
        pDate[i].month = (12 - i); 
        pDate[i].year = 2000 + i; 
    }

    printf("\n\n");
    for(int i = 0; i < N; i++) {
        printf("%d %d %d\n", (pDate + i) -> day, pDate[i].month, pDate[i].year);
    }
    printf("\n");

    free(pDate); 
    pDate = NULL;
}

void allocate_another_struct() {

    typedef struct tagPROFIT {
        unsigned short year; 
        double profit;
    }PROFIT; 

    typedef PROFIT PROFITS; 
    typedef PROFITS* PPROFITS;

    PPROFITS pStruct = NULL; 
    pStruct = (PPROFITS)calloc(N, sizeof(PROFITS));
    assert(pStruct != 0);

    for(int i = 0; i < N; i++) {
        pStruct[i].profit = i * 1000; 
        pStruct[i].year = 2020 + i; 
    }

    printf("\n\n"); 
    for(int i = 0; i < N; i++) {
        printf("%hu %.2lf\n", pStruct[i].year, pStruct[i].profit);
    }

    printf("\n");

    free(pStruct); 
    pStruct = 0;
}