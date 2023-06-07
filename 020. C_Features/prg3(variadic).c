extern int printf(const char* fmt, ...);
void sum(int nr, ...);

#include <stdarg.h> //header for macros, we are gonna use ahead

int main(void) {

    sum(3, 10, 20, 30);
    return (0);
}

void sum(int nr, ...) {
    int i = 0;
    int sum = 0;
    va_list ptr_to_arguments = NULL;
    
    /**
     * In the stack frame of sum 
     * Local variables exist in the stackframe
     * First nr then ...ellipsis
     * Here we tell macro, make ptr_to_arguments point to next to nr, to ellipsis 
     * We tell macro to make ptr_tp_arguments, point to ellipsis, which exist next to nr 
    */
    va_start(ptr_to_arguments, nr);

    for(i = 0; i < nr; i++)
        sum += va_arg(ptr_to_arguments, int);   //va_arg macro is as good as #define va_arg(ap,T) *(T*)ap; (T*)ap+=1
    va_end(ptr_to_arguments);                   //make ptr_to_arguments point to null
    printf("%d\n", sum);
}