/*
 * extern keyword in function declaration and variable declaration illustrates no memory allocation 
        i)  for Data Manipulation Statements in case of function 
        ii) for Data itself in case of variable decalration
*/

#include <stdio.h> 

extern void fun(void);
extern void gun(void);

extern int num1;
extern int num2 = 1;    //if value to assigned to extern variable, extern keyword is discarded

int main(void) {

    fun();
    gun();
}

extern void fun(void) {
    //unresolved external symbol num1 referenced in function fun
    //printf("%d = num1\n", num1); 
    printf("%d = num2\n", num2);
    
    printf("In fun\n");
}

extern void gun(void) {
    //error C2205: 'a': cannot initialize extern variables with block scope
    //extern int a = 10; 
    //printf("gun.a = %d\n", a);

    printf("In gun\n");
}