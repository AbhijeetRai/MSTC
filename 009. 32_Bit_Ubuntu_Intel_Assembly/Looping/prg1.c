#include <stdio.h> 
#include <stdlib.h> 

int i; 

int main(void){
	i = 0; 
	while(i < 5){
		printf("i = %d\n", i); 
		i = i + 1; 
	}
	puts("End of program"); 
	exit(0); 
}