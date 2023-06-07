#include <stdio.h> 
#include <stdlib.h> 


int main(void) {

    int a, b, c; 

    printf("Enter a:"); 
    scanf("%d", &a);

    printf("Enter b:"); 
    scanf("%d", &b);

    printf("Enter c:"); 
    scanf("%d", &c); 

    if(a > b) 
        printf("a > b\n");
    else if(a < b)
        printf("a < b\n");
    else if(a == b)
        printf("a == b\n");
    
    else if(b < c)
        printf("b < c\n");
    else if(b > c)
        printf("b > c\n");
    else if(b == c) 
        printf("b == c\n");
    
    else if(c < a)
        printf("c < a\n");
    else if(c > a)
        printf("c > a\n");
    else if(c == a) 
        printf("c == a\n");

    else 
        printf("else\n");

    exit(EXIT_SUCCESS);
}

/**
Exercise set 06, question 2 
Will control flow reach at bottom else (Line 40 in adjacent program)

In my understanding, control flow will revolve in line 18 - line 23 only. 
Because: 
    ∄? a, b ∃       a < b   ^   a > b   ^   a != b      a, b ∈ {I} 

There does not exist a pair of a, b from set of Integers such that 
a is less than b; a is greater than b; a is not equal b at same time 
If all of conditions above would have been satisfied, program flow 
would have moved beyond line 23. But there is no way, ALL(and in maths) 
conditions can be satisfied in maths. 
*/