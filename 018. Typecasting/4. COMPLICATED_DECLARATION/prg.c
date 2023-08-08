
/*
    Declare a function: 
        Which accepts pointer to a function accepting int, int and returning int 
        But functions itself returns pointer to array of 5 integers
*/

int (*test_function(int(*)(int, int))) [5];