#include <stdio.h> 
#include <stdlib.h> 

/*
void* memcpy (void *dest, const void *src, size_t len) {
    char *d = dest;
    const char *s = src;
    
    while (len--)
        *d++ = *s++;
    
    return (dest);
}
*/

void* memcopy(void* dest, const void* src, size_t n) {

    int i = 0; 
    while(i<n) {
        ((char*)dest)[i] = ((char*)src)[i];
        i += 1;
    }

    return dest;
}

typedef struct Date {

    int day; 
    int month; 
    int year;
}date;

int main(void) {

    date d1 = {1, 1, 21}; 
    date d2; 

    memcopy(&d2, &d1, sizeof(d1));
    printf("%d %d %d\n", d2.day, d2.month, d2.year);

    int i1 = 10; 
    int i2 = 0;
    memcopy(&i2, &i1, sizeof(int));
    printf("%d\n", i2);

    date d3 = {11, 11, 121}; 
    date d4; 

    memcpy(&d4, &d3, sizeof(d3));
    printf("%d %d %d\n", d4.day, d4.month, d4.year);

    int i11 = 1011; 
    int i12 = 0;
    memcpy(&i12, &i11, sizeof(int));
    printf("%d\n", i12);

    return (0);
}