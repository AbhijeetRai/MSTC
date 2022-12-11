#include <stdio.h>
#include <stdlib.h> 

#define NR_CHOICES 3

#define TRUE 1
#define FALSE 0

int main(void) {

    printf("1.Millimeter\n2.Centimeter\n3.Meter\n4.Kilometer\n5.Inch\n6.Foot\n7.Yard\n8.Mile\n");
    int from_choice = get_choice("\nEnter from choice:\n");
    int to_choice = get_choice("\nEnter to choice:\n");
}

int get_choice(const char* message) {

    int choice;
    int flag = FALSE;

    printf(message);

    for(int i = 1; i <= NR_CHOICES; ++i) {
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 8) {
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