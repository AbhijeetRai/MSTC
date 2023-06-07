/*
Structure padding: 
    i) Addresses of data types long long, double must be aligned to 8
    ii) Addresses of int, long and float must be aligned to 4 
    iii)Char and short fit in where padded memory is left in by 4 and 8 bytes aligned datatypes 
*/

/*
    MOSTLY, SHORT IS ALIGNED TO 2, WITH THE HELP OF INTERNAL PADDING. 
    RFERER ADDRESSING IN NEXT COUPLE OF PROGRAMS TO UNDERSTAND MORE
*/

//Told in class: Exception to the rules of padding will always be found
struct A {

    int a; 
    char b; 
    char c;
    short e;
};//size is 8 as expected

struct B {

    int a; 
    char b; 
    short e;    //short address is aligned to 2
    char c;
};//size is 12, an EXCEPTION !! But, why or how??

int main(void) {

    printf("size is %zu\n", sizeof(struct A)); //8 as expected 
    printf("size is %zu\n", sizeof(struct B)); //should have been 8, but why it is 12 an exception?

    struct B instance = {1, 'A', 1, 1};

    printf("%p %p %p %p %p\n", &instance, &instance.a, &instance.b, &instance.e, &instance.c);
}

/*
 * Some processrors cannot access unaligned addreses. 
 * Aligned members are accessed fast, let's say 't' 
 * Unaligned members are accessed with time '2t'
 * Read about internal padding (to keep struct members aligned) 
 * and tail padding (last variable padded)
*/