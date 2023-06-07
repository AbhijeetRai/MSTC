#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
    int roll; 
    double attendance; 
    double percentage;
}student;

void show_array(student* stu_ptr, int size, const char* msg);
void sort(
            student* stu_ptr, 
            int last_index, 
            int(*compare)(const student* s1, const student* s2)
        );
int compare_with_roll(const student* s1, const student* s2);
int compare_with_attendance(const student* s1, const student* s2);

int main(void) {

    student stu_arr[5] = {
                            {11, 66.4, 62.3},
                            {54, 81.5, 73.3},
                            {99, 87.3, 78.4}, 
                            {17, 21.3, 47.3},
                            {23, 13.5, 99.8}
                         };

    show_array(stu_arr, 5, "Before sort:");
    sort(stu_arr, 4, compare_with_roll);
    show_array(stu_arr, 5, "After sort with roll:");

    sort(stu_arr, 4, compare_with_attendance);
    show_array(stu_arr, 5, "After sort with attendance:");

    return (0);
}

void show_array(student* stu_ptr, int size, const char* msg) {

    if(msg) 
        puts(msg);

    for(int i = 0; i < size; i++) 
        printf("roll=%d attendance=%.2lf percentage=%.2lf\n", 
                stu_ptr[i].roll, stu_ptr[i].attendance, stu_ptr[i].percentage);
    printf("\n");
}

void sort(student* stu_ptr, int last_index, int(*compare)(const student*, const student* s2)) {

    for(int i = 1; i <= last_index; i++) {
        student key = stu_ptr[i];
        int j = i - 1;

        while(j >= 0 && compare(stu_ptr + j, &key) > 0) {
            stu_ptr[j+1] = stu_ptr[j];
            j -= 1;
        }
        stu_ptr[j+1] = key;
    }
}

int compare_with_roll(const student* s1, const student* s2) {
    if(s1->roll > s2->roll)
        return 1; 
    else    
        return -1;
}

int compare_with_attendance(const student* s1, const student* s2) {
    if(s1->attendance > s2->attendance)
        return 1; 
    else    
        return -1;
}