#include <stdio.h> 
#include <stdlib.h> 

struct A{
	long long n1; 
	long long n2; 
	int arr[5]; 
};

struct A inA = {
					0x10203040a0b0c0d0, 
					0xffa0ffb0ffc0ffd0, 
					{10, 20, 30, 40, 50}
				}; 

int n, i; 

int main(void){
	for(i = 0; i < 5; ++i){
		n = inA.arr[i]; 
		printf("n = %d\n", n); 
	}
	puts("end of program"); 
	exit(0); 
}

