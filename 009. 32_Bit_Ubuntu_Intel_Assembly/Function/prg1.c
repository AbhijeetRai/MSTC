#include <stdio.h> 
#include <stdlib.h> 

int cpa_add(int num1, int num2); 
int cpa_sub(int num1, int num2); 
int cpa_mul(int num1, int num2); 
int cpa_quotient(int num1, int num2); 
int cpa_remainder(int num1, int num2); 

int n1, n2; 
int result;

int main(void){
	printf("Enter n1:"); 
	scanf("%d", &n1); 

	printf("Enter n2:"); 
	scanf("%d", &n2); 

	result = cpa_add(n1, n2); 
	printf("%d + %d == %d\n", n1, n2, result); 

	result = cpa_sub(n1, n2); 
	printf("%d - %d == %d\n", n1, n2, result); 

	result = cpa_mul(n1, n2); 
	printf("%d * %d == %d\n", n1, n2, result); 

	result = cpa_quotient(n1, n2); 
	printf("%d / %d == %d\n", n1, n2, result); 

	result = cpa_remainder(n1, n2); 
	printf("%d %% %d == %d\n", n1, n2, result); 

	exit(EXIT_SUCCESS); 
}

int cpa_add(int n1, int n2){
	int sum; 
	sum = n1 + n2; 
	return (sum); 
}

int cpa_sub(int n1, int n2){
	int sub; 
	sub = n1 - n2; 
	return (sub); 
}

int cpa_mul(int n1, int n2){
	int mul; 
	mul = n1 * n2; 
	return (mul); 
}

int cpa_quotient(int n1, int n2){
	int quotient; 
	quotient = n1/n2; 
	return (quotient); 
}

int cpa_remainder(int n1, int n2){
	int remainder; 
	remainder = n1 % n2; 
	return (remainder); 
}
