#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(void) {

    char s1[] =  "VIDISHA RAI";
    char s2[] = {'V', 'I', 'D', 'I', 'S', 'H', 'A', ' ', 'R', 'A', 'I'};

    printf("%zd %zd\n", strlen(s1), strlen(s2));

    return 0;
}