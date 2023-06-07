/*
 * When type(&data) is not known, use void*
 * When type(&data_ptr) is uncertain, use void** 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

struct A {int a; };
struct B {double b; };
struct C {char c; };

void allocator(void** p_pointer, size_t size);

int main(void) {

    struct A* a_ptr = NULL;
    struct B* b_ptr = NULL;
    struct C* c_ptr = NULL;

    allocator(&a_ptr, sizeof(struct A)); 
    assert(a_ptr != NULL);

    allocator(&b_ptr, sizeof(struct A)); 
    assert(b_ptr != NULL);

    printf("END");
    return (0);
}

/*
 * When we do not know, what type of address will we hold, we use void*
 * Similarly, when we do not know, what kind of pointer we may hold. 
 * type(&data_ptr) is uncertain, proceed to use void**, it will work
*/
void allocator(void** p_pointer, size_t size) {
    void* ptr = NULL;

    ptr = malloc(size);
    if(ptr == NULL) {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    *p_pointer = ptr;
}