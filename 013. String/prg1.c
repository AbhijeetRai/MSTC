#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) {

    char s1[] = "Abhi Rai";
    /*
        s1 is as good as 
        {'A', 'b', 'h', 'i', ' ', 'R', 'a', 'i', '\0'}
        strlen(s1) = 9
    */

    char s2[] = {'A', 'b', 'h', 'i', ' ', 'R', 'a', 'i'};
    //no \0 at end appended on own, expect some garbae value appended at end

    printf("%s %d\n", s1, strlen(s1));
    printf("%s %d\n", s2, strlen(s2));

    exit(EXIT_SUCCESS);
}