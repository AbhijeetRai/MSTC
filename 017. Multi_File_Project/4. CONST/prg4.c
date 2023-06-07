/**
 * @goal: to understand concept of constant pointer 
 * @author: Abhijeet Rai 
 * @date: 26-04-2023
*/

#include <stdio.h>

extern void fun(void);

int main(void) {

    int dhoni_jersey_no = 7;                  //not a constant value 
    int* const ptr;                           //the ptr is constant 

    //cannot modify constant pointer later
    //l-value specifies const object
    //ptr = &dhoni_jersey_no;

    fun();
    return 0;
}

extern void fun(void) {

    int sachin_jersey_no = 10; 
    int* const ptr = &sachin_jersey_no;

    *ptr += 1;      //we can modify the pointee value, because pointee is not const 
                    //it is not pointer to const
    printf("%d = sachin_jersey_no\n", *ptr);
}