//String algorithms 
#include <stdio.h> 
#include <stdlib.h> 

int cpa_strlen(const char* msg);
void cpa_strncpy(char* dest, const char* src); 
void cpa_strncpy_max_char(char** dest_ptr, const char* src); 
char* cpa_concat_str(char* str1, char* str2); 


int cpa_strlen(const char* msg) {

    int i;
    
    for(i = 0; msg[i] != '\0'; ++i)
        NULL;

    return (i);
}

void cpa_strncpy(char* dest, const char* src) {

    int i;

    for(i = 0; src[i] != '\0'; ++i) 
        dest[i] = src[i];
    dest[i] = '\0';
}

//what if source string is not delimited by '\0'
void cpa_strncpy_max_char(char** dest_ptr, const char* src) {

    int N = 10;
    char* dest = (char*)malloc(sizeof(char) * (N + 1));

    if(dest == NULL) {
        printf("fatal:memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; src[i] != '\0' && i < N; i++)
        dest[i] = src[i];

    dest[i] = '\0';
    *dest_ptr = dest;
} 

char* cpa_concat_str(char* str1, char* str2) {

    int str_len1 = cpa_strlen(str1); 
    int str_len2 = cpa_strlen(str2);
    int str_len3 = str_len1 + str_len2 + 1;

    char* str3 = NULL; 
    str3 = (char*)malloc(sizeof(char) * str_len3);
    if(str3 == NULL) {
        printf("fatal: memory allocation failed");
        exit(EXIT_FAILURE);
    }
    

    int i; 
    for(i = 0; i < str_len1; i++)
        str3[i] = str1[i];

    int j;
    for(j = 0; j < str_len2; j++) {
        str3[i] = str2[j]; 
        i++;
    }
    str3[i] = '\0';
    return str3;
}

int main(void) {

    char* str1 = "Core Programming Academy";
    int len_str1 = cpa_strlen(str1);

    char* str2 = (char*)malloc(sizeof(char) * (len_str1 + 1));
    if(str2 == NULL) {
        printf("fatal: memory allocation failed");
        exit(EXIT_FAILURE);
    }

    cpa_strncpy(str2, str1);
    printf("%s\n", str2);
    
    char* str3 = "THIS IS A LONG STRING"; 
    char* str4 = NULL; 
    cpa_strncpy_max_char(&str4, str3);
    printf("%s\n", str4);

    char* str5 = "Hello, "; 
    char* str6 = "CPA World!";
    char* str7 = cpa_concat_str(str5, str6);
    printf("%s\n", str7);

    return 0;
}