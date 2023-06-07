#include <stdio.h> 
#include <stdlib.h> 

int main(void) {
	
	int arr1[3][3];
	int* arr2 = (int*)malloc(3 * 3 * sizeof(int));
	
	printf("%llu\n", arr1);		//arr1 = type(&arr1[0]) = int(*)[3]
	printf("%llu\n", arr2);		//arr2 = type(&arr2[0]) = int*
	
	return (0);
}