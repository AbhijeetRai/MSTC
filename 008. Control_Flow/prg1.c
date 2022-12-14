/*
    @AUTHOR: ABHIJEET RAI
    @DATE:   14/12/2022
    @GOAL:   TO CONVERT LENGTH MAGNITUDE FROM UNIT TO ANOTHER: SAME AS LENGTH CONVERTOR.C PROGRAM
*/
#include <stdio.h>
#include <stdlib.h> 

#define NR_CHOICES 3

#define TRUE 1
#define FALSE 0

#define MILLIMETER 1 
#define CENTIMETER 2 
#define METER      3 
#define KILOMETER  4
#define INCH       5 
#define FOOT       6 
#define YARD       7
#define MILE       8
#define EXIT       9

int get_choice(const char* message, int valid_start, int valid_end);
void do_conversion(double input_number, int from_choice, int to_choice); 

double mm_cm(double input_number);
double mm_m(double input_number);
double mm_km(double input_number);
double mm_inch(double input_number);
double mm_foot(double input_number);
double mm_yard(double input_number); 
double mm_mile(double input_number);

double cm_mm(double input_number); 
double m_mm(double input_number); 
double km_mm(double input_number);
double inch_mm(double input_number); 
double foot_mm(double input_number);
double yard_mm(double input_number);
double mile_mm(double input_number);

int main(void) {

    while(TRUE) {
        double input_number = 0.0;

        printf("1.Millimeter\n2.Centimeter\n3.Meter\n4.Kilometer\n5.Inch\n6.Foot\n7.Yard\n8.Mile\n9.Exit\n");
        
        int from_choice = get_choice("\nEnter from choice:\n", 1, 9);
        if(from_choice == EXIT)
            exit(EXIT_SUCCESS); 

        int to_choice = get_choice("\nEnter to choice:\n", 1, 9);
        if(to_choice == EXIT)
            exit(EXIT_SUCCESS);

        printf("\nEnter input number:\n");
        scanf("%lf", &input_number);

        do_conversion(input_number, from_choice, to_choice);
    }
}

void do_conversion(double input_number, int from_choice, int to_choice) {

    double output_number = 0.0;
    char* input_unit = NULL; 
    char* output_unit = NULL;
//---------------------------------------------------------------
    if(from_choice == MILLIMETER && to_choice == MILLIMETER) {

        output_number = input_number; 
        input_unit = "mm"; 
        output_unit = "mm";
    }

    else if(from_choice == MILLIMETER && to_choice == CENTIMETER) {

        output_number = mm_cm(input_number); 
        input_unit = "mm"; 
        output_unit = "cm";
    }

    else if(from_choice == MILLIMETER && to_choice == METER) {

        output_number = mm_m(input_number); 
        input_unit = "mm"; 
        output_unit = "m";
    }

    else if(from_choice == MILLIMETER && to_choice == KILOMETER) {

        output_number = mm_km(input_number); 
        input_unit = "mm"; 
        output_unit = "km";
    }

    else if(from_choice == MILLIMETER && to_choice == INCH) {

        output_number = mm_inch(input_number); 
        input_unit = "mm"; 
        output_unit = "inch";
    }

    else if(from_choice == MILLIMETER && to_choice == FOOT) {

        output_number = mm_foot(input_number); 
        input_unit = "mm"; 
        output_unit = "foot";
    }

    else if(from_choice == MILLIMETER && to_choice == YARD) {

        output_number = mm_yard(input_number); 
        input_unit = "mm"; 
        output_unit = "yard";
    }

    else if(from_choice == MILLIMETER && to_choice == MILE) {

        output_number = mm_mile(input_number); 
        input_unit = "mm"; 
        output_unit = "mile";
    }
//----------------------------------------------------------
    else if(from_choice == CENTIMETER && to_choice == MILLIMETER) {

        output_number = cm_mm(input_number); 
        input_unit = "cm"; 
        output_unit = "mm";
    }

    else if(from_choice == CENTIMETER && to_choice == CENTIMETER) {

        output_number = input_number; 
        input_unit = "cm"; 
        output_unit = "cm";
    }

    else if(from_choice == CENTIMETER && to_choice == METER) {

        output_number = mm_m(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "m";
    }

    else if(from_choice == CENTIMETER && to_choice == KILOMETER) {

        output_number = mm_km(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "km";
    }

    else if(from_choice == CENTIMETER && to_choice == INCH) {

        output_number = mm_inch(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "inch";
    }

    else if(from_choice == CENTIMETER && to_choice == FOOT) {

        output_number = mm_foot(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "foot";
    }

    else if(from_choice == CENTIMETER && to_choice == YARD) {

        output_number = mm_yard(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "yard";
    }

    else if(from_choice == CENTIMETER && to_choice == MILE) {

        output_number = mm_mile(cm_mm(input_number)); 
        input_unit = "cm"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == METER && to_choice == MILLIMETER) {

        output_number = m_mm(input_number); 
        input_unit ="m"; 
        output_unit = "mm";
    }

    else if(from_choice == METER && to_choice == CENTIMETER) {

        output_number = mm_cm(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "cm";
    }

    else if(from_choice == METER && to_choice == METER) {

        output_number = input_number; 
        input_unit ="m"; 
        output_unit = "m";
    }

    else if(from_choice == METER && to_choice == KILOMETER) {

        output_number = mm_km(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "km";
    }

    else if(from_choice == METER && to_choice == INCH) {

        output_number = mm_inch(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "inch";
    }

    else if(from_choice == METER && to_choice == FOOT) {

        output_number = mm_foot(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "foot";
    }

    else if(from_choice == METER && to_choice == YARD) {

        output_number = mm_yard(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "yard";
    }

    else if(from_choice == METER && to_choice == MILE) {

        output_number = mm_mile(m_mm(input_number)); 
        input_unit ="m"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == KILOMETER && to_choice == MILLIMETER) {

        output_number = km_mm(input_number); 
        input_unit ="km"; 
        output_unit = "mm";
    }

    else if(from_choice == KILOMETER && to_choice == CENTIMETER) {

        output_number = mm_cm(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "cm";
    }

    else if(from_choice == KILOMETER && to_choice == METER) {

        output_number = mm_m(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "m";
    }

    else if(from_choice == KILOMETER && to_choice == KILOMETER) {

        output_number = input_number; 
        input_unit ="km"; 
        output_unit = "km";
    }

    else if(from_choice == KILOMETER && to_choice == INCH) {

        output_number = mm_inch(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "inch";
    }

    else if(from_choice == KILOMETER && to_choice == FOOT) {

        output_number = mm_foot(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "foot";
    }

    else if(from_choice == KILOMETER && to_choice == YARD) {

        output_number = mm_yard(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "yard";
    }

    else if(from_choice == KILOMETER && to_choice == MILE) {

        output_number = mm_mile(km_mm(input_number)); 
        input_unit ="km"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == INCH && to_choice == MILLIMETER) {

        output_number = inch_mm(input_number); 
        input_unit ="inch"; 
        output_unit = "mm";
    }

    else if(from_choice == INCH && to_choice == CENTIMETER) {

        output_number = mm_cm(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "cm";
    }

    else if(from_choice == INCH && to_choice == METER) {

        output_number = mm_m(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "m";
    }

    else if(from_choice == INCH && to_choice == KILOMETER) {

        output_number = mm_km(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "km";
    }

    else if(from_choice == INCH && to_choice == INCH) {

        output_number = input_number; 
        input_unit ="inch"; 
        output_unit = "inch";
    }

    else if(from_choice == INCH && to_choice == FOOT) {

        output_number = mm_foot(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "foot";
    }

    else if(from_choice == INCH && to_choice == YARD) {

        output_number = mm_yard(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "yard";
    }

    else if(from_choice == INCH && to_choice == MILE) {

        output_number = mm_mile(inch_mm(input_number)); 
        input_unit ="inch"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == FOOT && to_choice == MILLIMETER) {

        output_number = foot_mm(input_number); 
        input_unit ="foot"; 
        output_unit = "mm";
    }

    else if(from_choice == FOOT && to_choice == CENTIMETER) {

        output_number = mm_cm(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "cm";
    }

    else if(from_choice == FOOT && to_choice == METER) {

        output_number = mm_m(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "m";
    }

    else if(from_choice == FOOT && to_choice == KILOMETER) {

        output_number = mm_km(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "km";
    }

    else if(from_choice == FOOT && to_choice == INCH) {

        output_number = mm_inch(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "inch";
    }

    else if(from_choice == FOOT && to_choice == FOOT ) {

        output_number = input_number; 
        input_unit ="foot"; 
        output_unit = "foot";
    }

    else if(from_choice == FOOT && to_choice == YARD) {

        output_number = mm_yard(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "yard";
    }

    else if(from_choice == FOOT && to_choice == MILE) {

        output_number = mm_mile(foot_mm(input_number)); 
        input_unit ="foot"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == YARD && to_choice == MILLIMETER) {

        output_number = yard_mm(input_number); 
        input_unit ="yard"; 
        output_unit = "mm";
    }

    else if(from_choice == YARD && to_choice == CENTIMETER) {

        output_number = mm_cm(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "cm";
    }

    else if(from_choice == YARD && to_choice == METER) {

        output_number = mm_m(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "m";
    }

    else if(from_choice == YARD && to_choice == KILOMETER) {

        output_number = mm_km(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "km";
    }

    else if(from_choice == YARD && to_choice == INCH) {

        output_number = mm_inch(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "inch";
    }

    else if(from_choice == YARD && to_choice == FOOT ) {

        output_number = mm_foot(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "foot";
    }

    else if(from_choice == YARD && to_choice == YARD) {

        output_number = input_number; 
        input_unit ="yard"; 
        output_unit = "yard";
    }

    else if(from_choice == YARD && to_choice == MILE) {

        output_number = mm_mile(yard_mm(input_number)); 
        input_unit ="yard"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    else if(from_choice == MILE && to_choice == MILLIMETER) {

        output_number = mile_mm(input_number); 
        input_unit ="mile"; 
        output_unit = "mm";
    }

    else if(from_choice == MILE && to_choice == CENTIMETER) {

        output_number = mm_cm(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "cm";
    }

    else if(from_choice == MILE && to_choice == METER) {

        output_number = mm_m(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "m";
    }

    else if(from_choice == MILE && to_choice == KILOMETER) {

        output_number = mm_km(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "km";
    }

    else if(from_choice == MILE && to_choice == INCH) {

        output_number = mm_inch(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "inch";
    }

    else if(from_choice == MILE && to_choice == FOOT ) {

        output_number = mm_foot(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "foot";
    }

    else if(from_choice == MILE && to_choice == YARD) {

        output_number = mm_yard(mile_mm(input_number)); 
        input_unit ="mile"; 
        output_unit = "yard";
    }

    else if(from_choice == MILE && to_choice == MILE) {

        output_number = input_number; 
        input_unit ="mile"; 
        output_unit = "mile";
    }
//----------------------------------------------------------------
    printf("\ninput number = %.2lf %s\noutput number = %.2lf %s\n", input_number, input_unit, output_number, output_unit);
}

double mm_cm(double input_number) {

    return (input_number/10.0);
}

double mm_m(double input_number) {

    return (input_number/1000.0);
}

double mm_km(double input_number) {

    return (input_number/1000000);
}

double mm_inch(double input_number) {

    return (input_number / 25.4);
}

double mm_foot(double input_number) {

    return (input_number / 304.8);
}

double mm_yard(double input_number) {

    return (input_number / 914.4);
}

double mm_mile(double input_number) {

    return (input_number / 1.609e+6);
}

double cm_mm(double input_number) {
    
    return (input_number * 10.0); 
}

double m_mm(double input_number) {

    return (input_number * 1000.0);
}

double km_mm(double input_number) {

    return (input_number * 1000000.0);
}

double inch_mm(double input_number) {

    return (input_number * 25.4);
}

double foot_mm(double input_number) {

    return (input_number * 304.8);
}

double yard_mm(double input_number) {

    return (input_number * 914.4);
}

double mile_mm(double input_number) {

    return (input_number * 1.609e+6);
}

int get_choice(const char* message, int valid_start, int valid_end) {

    int choice;
    int flag = FALSE;

    printf(message);

    for(int i = 1; i <= NR_CHOICES; ++i) {
        scanf("%d", &choice);
        if(choice >= valid_start && choice <= valid_end) {
            flag = TRUE; 
            break;
        }
        printf("Enter valid choice\n");
    }

    if(flag == FALSE) {

        printf("\nYou did not enter a valid choice\n");
        printf("Exiting application...\n");
        _getch();
        exit(EXIT_FAILURE);
    }

    return choice;
}
