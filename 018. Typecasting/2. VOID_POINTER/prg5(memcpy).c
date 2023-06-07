/*
 * C has an inbuilt routine memcpy 
 * might be looking like memcopy below 
*/

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

int main(void) {

    char* name1 = "Abhi";
    char* name2 = (char*)calloc(5, sizeof(char));
    memcopy(name2, name1, 5);
    printf("%s\n", name2);

    return(0);
}