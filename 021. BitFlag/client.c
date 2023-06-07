#include "lib.h" 

struct student s; 

int main(void) {
    s.size = sizeof(struct student);
    s.mask = ST_ALL;
    s.iroll = 10; 
    s.iattnd = 70; 
    s.imarks = 80;
    set(&s);

    s.mask = ST_ROLL | ST_MARKS; 
    get(&s); 
    show(&s);

    return (0);
}