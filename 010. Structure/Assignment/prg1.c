#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOCKET_STYLE_LENGTH     128
#define COLOR_LENGTH            32
#define BRAND_NAME_LENGTH       32

struct socket_details {
    char socket_style[SOCKET_STYLE_LENGTH];
    unsigned short frequency; //in Hz 
    unsigned short voltage;   //in Volts
};

struct socket_dimension {
    int length, breadth; // in cm
};

struct socket {

    char colour[COLOR_LENGTH];
    char brand[BRAND_NAME_LENGTH];

    struct socket_details details; 
    struct socket_dimension dimensions;
};

int main(void) {

    struct socket socket_instance; 

    strncpy(socket_instance.colour, "White", strlen("White"));
    strncpy(socket_instance.brand, "HAVELLS", strlen("HAVELLS"));
    strncpy(socket_instance.details.socket_style, "Indian", strlen("Indian"));
    
    socket_instance.details.frequency = 40; 
    socket_instance.details.voltage = 220;

    socket_instance.dimensions.length = 10;
    socket_instance.dimensions.breadth = 20; 

    printf("Socket color = %s\nSocket brand = %s\n", socket_instance.colour, socket_instance.brand);
    printf("\nSocket style = %s\nSocket frequency = %hu Hz\nSocket volts = %hu Volts\n", socket_instance.details.socket_style, socket_instance.details.frequency, socket_instance.details.voltage);
    printf("\nSocket length = %d cm\nSocket breadth = %d cm\n", socket_instance.dimensions.length, socket_instance.dimensions.breadth);

    return (EXIT_SUCCESS);
};