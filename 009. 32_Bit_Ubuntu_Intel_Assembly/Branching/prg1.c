#include <stdio.h> 
#include <stdlib.h> 

int n1, n2; 

int main(void){
	printf("Enter n1:"); 
	scanf("%d", &n1); 

	printf("Enter n2:"); 
	scanf("%d", &n2); 

	if(n1 > n2)
	{
		printf("%d > %d\n", n1, n2); 
	}

	puts("end of program"); 
	exit(0); 
}
