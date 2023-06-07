#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) {

    char s1[3] = "ABC";             //  \0 not appended, expect some garbage
    char s2[]  = "ABC";             //  \0 appended on own
    char s3[4] = "ABC";
    printf("%s %s %s\n", s1, s2, s3);

    char s4[] = "ABC\0";            // \0 being appended on own, no need to do it explicitly
    char* s5 = "ABC";               // \0 being appended on own
    char* s6 = "ABC\0";             // \0 being appended on own, no need to do it explicitly 
    printf("%s %s %s\n", s4, s5, s6);

    char s7[] = "\65";
    char* s8 = "A\66\67";
    char* s9 = "\65\66\67";
    printf("%s %s %s\n", s7, s8, s9);

    exit(EXIT_SUCCESS);
}