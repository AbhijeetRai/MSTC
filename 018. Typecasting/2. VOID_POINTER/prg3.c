#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
    int roll; 
    double attendance; 
    double percentage;
}student;

void show_array(student* stu_ptr, int size, const char* msg);
void sort_with_roll(student* stu_ptr, int last_index);
void sort_with_attendance(student* stu_arr, int last_index);
void sort_with_percentage(student* stu_arr, int last_index);

int main(void) {

    student stu_arr[5] = {
                            {11, 66.4, 62.3},
                            {54, 81.5, 73.3},
                            {99, 87.3, 78.4}, 
                            {17, 21.3, 47.3},
                            {23, 13.5, 99.8}
                         };
    show_array(stu_arr, 5, "Before sort: ");
    sort_with_roll(stu_arr, 4);
    show_array(stu_arr, 5, "After sort with roll: ");
    sort_with_attendance(stu_arr, 4);
    show_array(stu_arr, 5, "After sort with attendance: ");
    sort_with_percentage(stu_arr, 4);
    show_array(stu_arr, 5, "After sort with percentage: ");

    return (0);
}

void sort_with_roll(student* stu_ptr, int last_index) {

    for(int i = 1; i <= last_index; i++) {

        student key = stu_ptr[i];
        int j = i - 1;

        while(j >= 0 && stu_ptr[j].roll > key.roll) {
            stu_ptr[j+1] = stu_ptr[j];
            j -= 1;
        }
        stu_ptr[j+1] = key;
    }
}

void sort_with_attendance(student* stu_arr, int last_index) {

    for(int i = 1; i <= last_index; i++) {

        student key = stu_arr[i];
        int j = i - 1;

        while(j >= 0 && stu_arr[j].attendance > key.attendance) {
            stu_arr[j+1] = stu_arr[j];
            j -= 1;
        }
        stu_arr[j+1] = key;
    }
}

void sort_with_percentage(student* stu_arr, int last_index) {

    for(int i = 1; i <= last_index; i++) {

        student key = stu_arr[i];
        int j = i - 1;

        while(j >= 0 && stu_arr[j].percentage > key.percentage) {
            stu_arr[j+1] = stu_arr[j];
            j -= 1;
        }
        stu_arr[j+1] = key;
    }
}

void show_array(student* stu_ptr, int size, const char* msg) {

    if(msg) 
        puts(msg);

    for(int i = 0; i < size; i++) 
        printf("roll=%d attendance=%.2lf percentage=%.2lf\n", 
                stu_ptr[i].roll, stu_ptr[i].attendance, stu_ptr[i].percentage);
    printf("\n");
}