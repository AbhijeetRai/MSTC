/*
 * Allocating and fetching data from a 2D Array
*/

/*
 * Array access generalised formula: 
 * Let's say we have an int array(dynamically allocated): arr[N1][N2] 
 *
 * And we want to access arr[i1][i2]: it means, we have to move ahead 
 * arr + (i1 * sizeof(int) * N2) + (i2 * sizeof(int))
 * Which is
 * arr + sizeof(int)(i1 * N2 + i2) .... [(equation I)]
 *
 * Fortunately, "+" on base address in C, is already type sensitive, it means if 
 * &int_var + 1, it by default means &int_var + 1*sizeof(int), that is, &int_var + 4
 * 
 * So removing sizeof(int) from above equation I, we get 
 * arr + (i1 * N2 + i2) 
 * 
 * To access[i1][i2] from base address of dynamically created 2D array, we have to move ahead by: arr + i1 * N2 + i2 bytes. 
 * Do not forget to dereference, it leads to 
 *
 * *(arr + i1 * N2 + i2)
*/

#include <stdio.h>
#include <stdlib.h> 

int main(void) {
	int row = 0;
	int column = 0;
	int* arr = 0;
	
	printf("Enter number of rows and number of column: rows columns: ? ");
	scanf("%d %d", &row, &column);
	
	arr = (int*)malloc(row * column * sizeof(int));
	if(arr == NULL) {
		printf("fatal: out of memory:");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			printf("arr[%d][%d]: %d\n", i, j, *(arr + i * column + j));
	printf("\n");
	
	return (0);
}