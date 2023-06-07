
int main(void) {

    #ifndef val 
        printf("Not define");
        #define ADD(A,B) A+B
    #endif

    ADD(1,2);
}