/**
 * @goal: to understand concept of pointer to const (pointee is constant)
 * @author: Abhijeet Rai 
 * @date: 26-04-2023
*/

int main(void) {

    const int dhoni_jersey_no = 7; 
    
    /**
     *  We want to avoid this, modification of const data
     *  
     *  int* ptr = &dhoni_jersey_no; 
     *  *ptr = 8;
     *  printf("%d\n", *ptr);
     * 
     *  Here const data existed on stack, hence code worked, data was modified
     *  even if it was not intended
     *  
     *  BUT THERE WILL BE GRAVE (SEG_FAULT) CONSEQUENCES, IF DATA EXISTS ON RODATA 
     *  AND WE GO TO MODIFY IT, LEADS TO SEG_FAULT AT RUNTIME. WE WANT TO MAKE SURE 
     *  AT COMPILE TIME ONLY CONST DATA SHOULD NOT BE MODIFIED WITH POINTER BACKDOOR 
     *  
     *  HENCE USE POINTER TO CONST
    */

    //pointer to const int
    const int* pointer;
    pointer = &dhoni_jersey_no;
    *pointer = 8;   //does not work, l-value specifies const object
    printf("%d\n", *pointer);

    return 0;
}