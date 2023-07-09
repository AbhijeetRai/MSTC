#include <stdio.h> 
#include <stdlib.h> 

int a, b; 
int m, n; 
int x, y; 

int main(void){
	printf("Enter a:"); 
	scanf("%d", &a); 

	printf("Enter b:"); 
	scanf("%d", &b); 

	printf("Enter m:"); 
	scanf("%d", &m); 

	printf("Enter n:"); 
	scanf("%d", &n); 

	printf("Enter x:"); 
	scanf("%d", &x); 

	printf("Enter y:"); 
	scanf("%d", &y); 

	if(a >= b){
		puts("a >= b"); 
	}else if(m < n){
		puts("a < b and m < n"); 
	}else if(x == y){
		puts("a < b and m >= n and x == y"); 
	}else{
		puts("a < b and m >= n and x != y"); 
	}

	puts("End of program"); 
	exit(0); 
	
}
