//Use this command to define X, Y and Z at the run time 
//cl /DX /DY def_from_cmd.c
#include <stdio.h> 

int main(void) {

    puts("start");

    #ifdef X 
        puts("X defined");
    #endif

    #ifdef Y 
        puts("Y defined");
    #endif

    puts("end");
}

/**
 * Personal: Sir since kernel deals with interrupt, which in turn requires knowledge of hardware 
 * We have targeted books for computer organisation, which teach to build 16 bit computer 
 * And then we can get started post mstc -> build computer -> "good" knowledge of linux bash and admin 
 * and then kernel
*/