/**
 * Declare a function accepting 
 *      an integer 
 *      pointer to a function: which accepts int and returns void
 * 
 * return: pointer to a function which accepts int and returns void  
 *      
*/

/*CORRECT LOGICALLY, BUT NOT SYNTAX: */ void(*)(int) function (int, void (*)(int))
/*CORRECT SYNTAX: */ void (*function(int, void(*)(int))) (int)

//is not as same as 
//void ((*)function(int, void(*)(int))) (int) 
