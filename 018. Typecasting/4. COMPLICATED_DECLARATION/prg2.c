/*
 * https://codebrowser.dev/glibc/glibc/stdlib/stdlib.h.html#__compar_d_fn_t
 * Find out meaning of line 823, 841
*/

int main(void) {

    //typedef int (*)[5] ptr_to_arr  //: this does not work
    typedef int (*ptr_to_arr)[5] ;

    ptr_to_arr ptr1=0; 
    printf("%llu %llu\n", ptr1, ptr1 + 1);

    return (0);
}