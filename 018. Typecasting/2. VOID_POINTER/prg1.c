#include <stdio.h> 
#include <stdlib.h> 

typedef struct Date {
    int day; 
    int month;
    int year;
}Date;

/*Little endian encoding*/
/*For epoch date 1, 1, 1970*/
char arr[12] = {
                    0x1, 0x0, 0x0, 0x0,
                    0x1, 0x0, 0x0, 0x0,
                    0xB2, 0x7, 0x0, 0x0
                };

int main(void) {
    void* p = NULL;
    p = arr; 

    int day = ((Date*)p)->day;
    /*
     * Offset of month in Date is 8, 
     * But p points to arr BASE, hence data will be read from offset 8 of arr 
     * Since month is type int, 4 bytes data will be read
     * read 4 bytes of data from arr on offset 8
    */
    int month = ((Date*)p)->month;
    int year = ((Date*)p)->year;

    printf("%d-%d-%d\n", day, month, year);

    return (0);
}