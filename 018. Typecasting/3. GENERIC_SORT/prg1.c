/*
 * THIS SORT WORKS PERFECTLY FINE FOR SORTING STUDENTS (with roll or attendace) 
 * WHAT IF I WANT TO SORT BOOKS, DOES THIS WORK?
*/

#include <stdio.h> 
#include <stdlib.h> 

/*
 * THIS SORT WORKS PERFECTLY FINE FOR SORTING STUDENTS (with roll or attendace) 
 * WHAT IF I WANT TO SORT BOOKS STRUCT, DOES THIS WORK?
*/

typedef struct student {
    int roll;
    double attendance; 
    double percentage;
}student;

void show_arr(const char* msg, student* stu_ptr, int size);
int sort_with_roll(const student* s1, const student* s2); 
int sort_with_attendance(const student* s1, const student* s2); 
void sort(student* stu_ptr, int last_index, int(*compare)(const student*, const student*)); 

int main(void) {

    student stu_arr[5] = {
                            {11, 66.4, 62.3},
                            {54, 81.5, 73.3},
                            {99, 87.3, 78.4},
                            {17, 21.3, 47.3},
                            {23, 13.5, 99.8}
                        };

    show_arr("Students before sorting:", stu_arr, 5);
    sort(stu_arr, 4, sort_with_roll);
    show_arr("Students after sorting with roll:", stu_arr, 5);
    return (0);
}

void show_arr(const char* msg, student* stu_ptr, int size) {

    if(msg) 
        puts(msg); 

    for(int i = 0; i < size; i++)
        printf("roll=%d attendance=%.2lf percentage=%.2lf\n", 
                stu_ptr[i].roll, stu_ptr[i].attendance, stu_ptr[i].percentage);
    printf("\n");
}

/*
 * THIS SORT WORKS PERFECTLY FINE FOR SORTING STUDENTS (with roll or attendace) 
 * WHAT IF I WANT TO SORT BOOKS STRUCT, DOES THIS WORK?
*/

void sort(student* stu_ptr, int last_index, int(*compare)(const student*, const student*)) {

    for(int i = 1; i <= last_index; i+=1) {
        student key = stu_ptr[i];
        int j = i - 1;

        while(j >= 0 && compare(stu_ptr + j, &key)) {
            stu_ptr[j + 1] = stu_ptr[j];
            j -= 1;
        }
        stu_ptr[j + 1] = key;
    }
}

int sort_with_roll(const student* s1, const student* s2) {
    if(s1->roll > s2->roll)
        return 1; 
    else 
        return 0;
}

int sort_with_attendance(const student* s1, const student* s2) {
    if(s1->attendance > s2->attendance)
        return 1; 
    else    
        return 0;
}