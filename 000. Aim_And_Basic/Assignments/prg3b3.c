#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void my_exit() {
    printf("Terminating...\n");
    _getch();
    exit(EXIT_FAILURE);
}

int main(void) {

    double a, b, c; 
    
    printf("Enter: a b c: "); 
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double discriminant = (b * b) - (4 * a * c);

    printf("discriminant = %lf\n", discriminant);

    if(a == 0) {
        printf("a cannot be 0\n");
        my_exit();
    }

    if(discriminant < 0) {
        printf("Discriminant: b^2 - 4ac cannot be negative\n");
        my_exit();
    }

    double discriminant_root = sqrt(discriminant);

    double root1 = ((-b) + discriminant_root) / (2 * a);
    double root2 = ((-b) - discriminant_root) / (2 * a);

    printf("%lf %lf\n", root1, root2);

    exit(EXIT_SUCCESS);
}