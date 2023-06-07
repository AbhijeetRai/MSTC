/*
 * SHOWN CODE WORKS FOR:
 * STRUCT STUDENTS SORTING (with attendance)
 * STRUCT BOOKS SORTING (with grade)
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <assert.h>

typedef struct student {
    int roll;
    double attendance; 
}student;

typedef struct book {
    char grade; 
    int price; 
}book;

void show_arr(const void* base_addr, int size, int offset, const char* message);
int sort_with_attendance(const student* s1, const student* s2);
int sort_with_grade(const book* b1, const book* b2); 
void sort(void* struct_ptr, int last_index, int offset, int(*sort)(const void*, const void*)); 

int main(void) {

    student stu_arr[5] = {{11, 16.7}, {13, 21.3}, {41, 80.1}, {54, 92.3}, {99, 77.8}};
    book book_arr[5] = {{'B', 61}, {'A', 13}, {'Z', 21}, {'C', 23}, {'D', 11}};
    show_arr(stu_arr, 5, sizeof(student), "Students before sorting: ");
    show_arr(book_arr, 5, sizeof(book), "Books before sorting: ");

    sort(stu_arr, 4, sizeof(student), sort_with_attendance);
    show_arr(stu_arr, 5, sizeof(student), "Students after sorting with attendance: ");

    sort(book_arr, 4, sizeof(book), sort_with_grade);
    show_arr(book_arr, 5, sizeof(book), "Books after sorting with grade: ");

    return (0);
}

void show_arr(const void* base_addr, int size, int offset, const char* message) {
    int i = 0;

    if(message) 
        puts(message);

    for(i = 0; i < size; i += 1) {
        if(offset == 16) {
            student* s = (student*)((char*)base_addr + (i * offset));
            printf("roll = %d attendance = %.2lf\n", s->roll, s->attendance);
        } else {
            book* b = (book*)((char*)base_addr + (i * offset));
            printf("grade = %c price = %d\n", (*b).grade, (*b).price);
        }
    }
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

void sort(void* struct_ptr, int last_index, int offset, int(*sort)(const void*, const void*)) {

    for(int i = 1; i <= last_index; i++) {
        void* key = NULL;
        
        key = malloc(offset);
        if(key == NULL) {
            printf("fatal: out of memory\n");
            exit(EXIT_FAILURE);
        }

        memcpy(key, (char*)struct_ptr + i * offset, offset);
        int j = i - 1;
        
        while(j >= 0 && sort((char*)struct_ptr + j*offset, key)) {
            memcpy((char*)struct_ptr + (j+1)*offset, (char*)struct_ptr + j*offset, offset);
            j -= 1;
        }
        memcpy((char*)struct_ptr + (j+1)*offset, key, offset);

        free(key); 
        key = NULL;
    }   
}