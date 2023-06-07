/*
    @goal: To build understanding of the command line arguments 
    @date: 
*/
extern int printf(const char*, ...);

int main(int argc, char** argv) {

    for(int i = 0; i < argc; i += 1) 
        printf("argv[%d]:%s\n", i, argv[i]);
    return (0);
}