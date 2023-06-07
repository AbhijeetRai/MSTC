#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct student {
    int roll; 
    double attendance;
}student;

typedef struct book {
    char grade; 
    int price; 
}book;

void show_student_array(const char* message, student* stu_arr, int size);
void show_book_array(const char* message, book* book_arr, int size);
int sort_with_attendance(const student* s1, const student* s2); 
int sort_with_grade(const book* b1, const book* b2);
void generic_qsort(void* struct_ptr, int p, int r, int(*compare)(const void*, const void*), int offset);
int partition(void* struct_ptr, int p, int r, int(*compare)(const void*, const void*), int offset);

int main(void) {

    student stu_arr[5] = {{11, 16.7}, {13, 21.3}, {41, 80.1}, {54, 92.3}, {99, 77.8}};
    show_student_array("Unsorted students array:", stu_arr, 5);
    book book_arr[5] = {{'B', 61}, {'A', 13}, {'Z', 21}, {'C', 23}, {'D', 11}};
    show_book_array("Unsorted books array: ", book_arr, 5);

    generic_qsort(stu_arr, 0, 4, sort_with_attendance, sizeof(student));
    show_student_array("Sorted students array with attendance:", stu_arr, 5);
    
    generic_qsort(book_arr, 0, 4, sort_with_grade, sizeof(book));
    show_book_array("Sorted books array with grade: ", book_arr, 5);

    return (0);
}

void generic_qsort(void* struct_ptr, int p, int r, int(*compare)(const void*, const void*), int offset) {

    if(p<r) {
        int q = partition(struct_ptr, p, r, compare, offset);
        generic_qsort(struct_ptr, p, q - 1, compare, offset);
        generic_qsort(struct_ptr, q + 1, r, compare, offset);
    }
}

int partition(void* struct_ptr, int p, int r, int(*compare)(const void*, const void*), int offset) {
    void* pivot = NULL; 
    int j = p; 
    int i = p - 1;
    void* temp = NULL;

    pivot = malloc(offset);
    if(pivot == NULL) {
        printf("fatal: out of memory\n");
        exit(EXIT_FAILURE);
    }
    temp = malloc(offset);
    if(temp == NULL) {
        printf("fatal: out of memory\n");
        exit(EXIT_FAILURE);
    }

    memcpy(pivot, (char*)struct_ptr + r * offset, offset);

    for(; j< r; j++) {
        if(compare((char*)struct_ptr + j * offset, pivot) == 0) {
            i += 1; 
            memcpy(temp, (char*)struct_ptr + i * offset, offset);
            memcpy((char*)struct_ptr + i * offset, (char*)struct_ptr + j * offset, offset);
            memcpy((char*)struct_ptr + j * offset, temp, offset);
        }
    }

    i += 1;
    memcpy(temp, (char*)struct_ptr + i * offset, offset);
    memcpy((char*)struct_ptr + i * offset, (char*)struct_ptr + j * offset, offset);
    memcpy((char*)struct_ptr + j * offset, temp, offset);

    free(pivot); 
    free(temp);

    return i;
}

void show_student_array(const char* message, student* stu_arr, int size) {

    if(message) 
        puts(message);

    for(int i = 0; i < size; i++)
        printf("roll = %d attendance = %.2lf\n", stu_arr[i].roll, stu_arr[i].attendance);
    printf("\n");
}

void show_book_array(const char* message, book* book_arr, int size) {

    if(message) 
        puts(message);

    for(int i = 0; i < size; i++)
        printf("grade = %c price = %.d\n", book_arr[i].grade, book_arr[i].price);
    printf("\n");
}

int sort_with_attendance(const student* s1, const student* s2) {
    if(s1->attendance > s2->attendance) 
        return (1); 
    else 
        return(0);
}

int sort_with_grade(const book* b1, const book* b2) {
    if(b1->grade > b2->grade)
        return (1);
    else 
        return (0);
}