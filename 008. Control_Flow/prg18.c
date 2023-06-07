#include <stdio.h> 
#include <stdlib.h> 


int* get_array(int* size_ptr);
void show_array(const char* message, int* array, int size); 
void clone_arrays(int* array1, int size, int** array2_ptr, int* array2_size_ptr, int** array3_ptr, int* array3_size_ptr, int** array4_ptr, int* array4_size_ptr);
int isPrime(int number); 


#define TRUE    1
#define FALSE   0

int main(void) {

    int N1 = 0;             //variable to store the length of first array A1
    int* array1 = get_array(&N1);
    show_array("Original array: ", array1, N1);

    int* array2 = NULL; 
    int N2 = 0; 
    int* array3 = NULL; 
    int N3 = 0;
    int* array4 = NULL; 
    int N4 = 0;
    clone_arrays(array1, N1, &array2, &N2, &array3, &N3, &array4, &N4);

    show_array("Even array: ", array2, N2);
    show_array("Odd array: ", array3, N3);
    show_array("Prime array: ", array4, N4);

    free(array1);
    array1 = 0;
    free(array2);
    array2 = 0;
    free(array3);
    array3 = 0; 
    free(array4);
    array4 = 0;

    return 0;
}

int* get_array(int* size_ptr) {
    
    int N1 = 0; 
    printf("Enter size of array1: "); 
    scanf("%d", &N1);

    if(N1 <= 5) {
        printf("Array must consist 6 or more elements\n");
        _getch();
        exit(EXIT_FAILURE);
    }

    int* array1 = (int*)malloc(sizeof(int) * N1);
    if(array1 == NULL) {
        printf("fatal: out of memory\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N1; i++) 
        array1[i] = rand() % 100 + 1;

    *size_ptr = N1;
    return array1;
}

void show_array(const char* message, int* array, int size) {

    if(message) 
        printf(message);

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("\n");
}

int isPrime(int number) {

    int flag = TRUE;

    if(number <= 1) 
        return 0;

    for(int i = 2; i < (number /2); i++) 
        if(number % i == 0) {
            flag = FALSE;
            break; 
        }
    return flag;
    
}

void clone_arrays(int* array1, int size, int** array2_ptr, int* array2_size_ptr, int** array3_ptr, int* array3_size_ptr, int** array4_ptr, int* array4_size_ptr) {

    int N1 = 0; 
    int N2 = 0;
    int N3 = 0;

    for(int i = 0; i < size; i++) {
        if(array1[i] % 2 == 0) 
            N1 += 1; 
        else 
            N2 += 1; 

        if(isPrime(array1[i]) == TRUE) 
            N3 += 1;
    }

    int* array2 = (int*)malloc(sizeof(int) * N1);
    if(array2 == NULL) {
        printf("fatal: array2: out of memory\n");
        exit(EXIT_FAILURE);
    }

    int* array3 = (int*)malloc(sizeof(int) * N2);
    if(array3 == NULL) {
        printf("fatal: array3: out of memory\n");
        exit(EXIT_FAILURE);
    }

    int* array4 = (int*)malloc(sizeof(int) * N3);
    if(array4 == NULL) {
        printf("fatal: array4: out of memory\n");
        exit(EXIT_FAILURE);
    }

    int x = 0, y = 0, z = 0;
    for(int i = 0; i < size; i++) {
        if(array1[i] % 2 == 0) {
            array2[x] = array1[i]; 
            x++;
        }
        
        else {
            array3[y] = array1[i]; 
            y++;
        }

        if(isPrime(array1[i]) == TRUE) {
            array4[z] = array1[i]; 
            z++;
        }
    }

    *array2_ptr = array2; 
    *array2_size_ptr = N1;

    *array3_ptr = array3; 
    *array3_size_ptr = N2;

    *array4_ptr = array4;
    *array4_size_ptr = N3;
}