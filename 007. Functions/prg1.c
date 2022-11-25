/*
    @AUTHOR: Abhijeet Rai 
    @DATE: 24/11/22
    @GOAL: To demonstrate format specifiers of printf()
*/

int printf(const char*, ...); 
void exit(int);
void test_printf(void);

int num = 145;

int main(void) {

    printf("This is a start of a program\n");
    printf("The value inside variable num is %d\n", num);
    test_printf();
    exit(0);
}

void test_printf(void) {

    char c1 = 'T';
    char c2 = -34; 
    unsigned char c3 = 129;

    short int s_num = 23912; 
    unsigned short int us_num = 21982;

    int i_num = -549543;
    unsigned int ui_num = 34285322;

    long int lng_num = 524535;
    unsigned long int ulng_num = 2356;

    long long int lng_lng_num = 3453265353;
    unsigned long long int u_lng_lng_num = 2355256432;

    float f_num = 3.6543576; 
    double d_num = 23536.36525252536;

    printf("c1 = %c\n", c1);
    printf("c2 = %hhd\n", c2);
    printf("c3 = %hhu\n", c3);

    printf("\n");

    printf("s_num = %hd\n", s_num);
    printf("us_num = %hu\n", us_num);

    printf("\n");

    printf("i_num = %d\n", i_num);
    printf("ui_num = %u\n", ui_num);

    printf("\n");

    printf("lng_num = %ld\n", lng_num);
    printf("ulng_num = %lu\n", ulng_num);

    printf("\n");

    printf("lng_lng_num = %lld\n", lng_lng_num);
    printf("u_lng_lng_num = %llu\n", u_lng_lng_num);
}