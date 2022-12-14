#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

#define TO_MICROGRAMS   0
#define FROM_MICROGRAMS 1

#define NR_CHOICES  3

#define MICROGRAM   1 
#define MILLIGRAM   2 
#define GRAM        3 
#define KILOGRAM    4 
#define TON         5 
#define STONE       6
#define POUND       7
#define OUNCE       8

#define EXIT    9

int get_choice(char const* message, int valid_start, int valid_end);
double convert(int choice, double input_number, int conversion_type);

char* input_unit;
char* output_unit;

int main(void) {
    
    while(TRUE) {

        double input_number;
        printf("\n***\n1.Micrograms(mcg)\n2.Milligrams(mg)\n3.Grams(g)\n4.Kilograms(kg)\n5.Tons(t)\n6.Stone(st)\n7.Pound(lb)\n8.Ounces(oz)\n9.Exit\n");
            
        int from_choice = get_choice("\nEnter from choice:", 1, 9);
        if(from_choice == EXIT)
            exit(EXIT_SUCCESS); 

        printf("Enter magnitude:");
        scanf("%lf", &input_number);

        int to_choice = get_choice("Enter to choice:", 1, 9);
        if(to_choice == EXIT)
            exit(EXIT_SUCCESS);

        double input_converted_to_micrograms = convert(from_choice, input_number, TO_MICROGRAMS);
        double micrograms_converted_to_output = convert(to_choice, input_converted_to_micrograms, FROM_MICROGRAMS);
        printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, micrograms_converted_to_output, output_unit);
        printf("***\n");
    }
    return 0;
}

int get_choice(char const* message, int valid_start, int valid_end) {

    int choice;
    int FLAG = FALSE;
    printf("%s", message); 

    for(int i = 1; i <= NR_CHOICES; i++) {
        scanf("%d", &choice);

        if(choice >= valid_start && choice <= valid_end) {
            FLAG = TRUE; 
            break;
        }

        if(NR_CHOICES != i)
            printf("Enter valid choice:"); 
    }

    if(FLAG == FALSE) {
        printf("\nNo valid choice entered in %d attempts\nExiting application...\n", NR_CHOICES);
        _getch();
        exit(EXIT_FAILURE);
    }

    return choice;
}

double convert(int choice, double input_number, int conversion_type) {

    double output_number = 0.0; 

    switch(choice) {
        
        case MICROGRAM: 
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number;
                input_unit = "mcg";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number; 
                output_unit = "mcg";
            }
            break; 

        case MILLIGRAM: 
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 1000;
                input_unit = "mg";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 0.001; 
                output_unit = "mg";
            }
            break; 

        case GRAM: 
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 1000000;
                input_unit = "g";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 0.000001;
                output_unit = "g";
            }
            break;

        case KILOGRAM:
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 1e+9;
                input_unit = "kg";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 1e-9;
                output_unit = "kg";
            }
            break;

        case TON:
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 1e+12;
                input_unit = "t";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 1e-12;
                output_unit = "t";
            }
            break;

        case STONE: 
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 6.350293e+9;
                input_unit = "st";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 1.57473e-10;
                output_unit = "st";
            }
            break;

        case POUND: 
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 4.535924e+8;
                input_unit = "lb";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 2.204623e-9;
                output_unit = "lb"; 
            }
            break;

        case OUNCE:
            if(conversion_type == TO_MICROGRAMS) {
                output_number = input_number * 2.834952e+7;
                input_unit = "oz";
            } else if (conversion_type = FROM_MICROGRAMS) {
                output_number = input_number * 3.527396e-8;
                output_unit = "oz";
            }
            break;
    }

    return output_number;
}