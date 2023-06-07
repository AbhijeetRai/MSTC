#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

#include <stdlib.h> 
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h> 
#include <stdlib.h> 

#include <assert.h> 
#include <assert.h>
#include <assert.h>
#include <assert.h>
#include <assert.h> 

#include <string.h> 
#include <string.h> 
#include <string.h> 
#include <string.h> 
#include <string.h> 

#include <Windows.h> 
#include <Windows.h>
#include <Windows.h>
#include <Windows.h>
#include <Windows.h>

void test_1(void) {
    
    char* p_char = NULL; 
    p_char = (char*)malloc(sizeof(char));
    if(p_char == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE);
    }

    *p_char = 'A'; 
    printf("*p_char = %c\n", *p_char); 
    free(p_char); 
    p_char = NULL;

    short* p_short = NULL; 
    p_short = (short*)malloc(sizeof(short));
    if(p_short == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE);
    }

    *p_short = 56434; 
    printf("*p_short = %hd\n", *p_short); 
    free(p_short);
    p_short = NULL; 

    float* p_float = NULL; 
    p_float = (float*)malloc(sizeof(float));
    if(p_float == NULL) {
        puts("Error in allocating memory\n"); 
        exit(EXIT_FAILURE);
    }

    *p_float = 3.14f; 
    printf("*p_float = %f\n", *p_float); 
    free(p_float); 
    p_float = NULL;



    struct Date {
        int day; 
        int month; 
        int year;
    };

    struct Date* p_date = NULL; 
    p_date = (struct Date*)malloc(sizeof(struct Date));
    if(p_date == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE);
    }

    p_date -> day = 1; 
    p_date -> month = 1; 
    p_date -> year = 1970; 

    printf("%d-%d-%d\n", p_date -> day, p_date -> month, p_date -> year);
    free(p_date); 
    p_date = NULL;
}

void Test2(void) {

    int* pInt = NULL; 
    pInt = (int*)malloc(sizeof(int)); 
    if(pInt == NULL) {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    *pInt = 100; 
    printf("*pInt = %d\n", *pInt);
    free(pInt); 
    pInt = NULL; 

    typedef double DOUBLE;
    DOUBLE* pDbl = NULL; 

    pDbl = (DOUBLE*)malloc(sizeof(DOUBLE)); 
    if(pDbl == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE);
    }

    *pDbl = 6.28; 
    printf("*pDbl = %lf\n", *pDbl);
    free(pDbl);
    pDbl = NULL; 

    typedef unsigned int UINT; 
    UINT* puInt = NULL; 

    puInt = (UINT*)malloc(sizeof(UINT));
    if(puInt == NULL) {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    *puInt = 345445; 
    printf("*puInt = %u\n", *puInt);
    free(puInt); 
    puInt = NULL;  



    typedef struct tagNode {
        INT iData; 
        struct tagBnode* prevLink; 
        struct tagNode* nextLink; 
    }NODE, *PNODE;

    PNODE pNode = (PNODE)malloc(sizeof(NODE)); 
    if(pNode == NULL) {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    pNode -> iData = 1000; 
    pNode -> nextLink = pNode;
    pNode -> prevLink = pNode; 

    free(pNode); 
    pNode = NULL;

}