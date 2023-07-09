#include <stdio.h> 
#include <stdlib.h> 

int a; 
int b; 
int c; 
int d; 

int main(void){
	printf("Enter a:"); 
	scanf("%d", &a); 

	printf("Enter b:"); 
	scanf("%d", &b); 

	printf("Enter c:"); 
	scanf("%d", &c); 

	printf("Enter d:"); 
	scanf("%d", &d); 

	if(a >= b && c < d)
		puts("a >= b and c < d"); 

	if(a >= b || c < d)
		puts("a >= b or c < d or both"); 

	puts("End of program"); 
	exit(0); 
}


