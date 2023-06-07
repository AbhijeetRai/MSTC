extern int printf(const char*, ...);
void* malloc(int);
int fun(int, char*);

typedef int(*function_pointer)(int, char*);

int main(void) {

    function_pointer ptr = fun;

    char* value = (char*)malloc(sizeof(char));
    *value = 'A';

    ptr(10, value);

    return (0);
}

int fun(int number, char* ptr) {
    printf("*ptr in fun is %c+%d\n", *ptr, number);
    return (10);
}