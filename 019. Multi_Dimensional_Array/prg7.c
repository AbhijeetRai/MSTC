/*
 * @goal: To dynamically create a 3D array and access individual members
*/

/*
 * Let's say we have an array of type double which is dynamically allocated: arr[N1][N2][N3]
 * To access arr[i1][i2][i3], we have to move ahead by: 
 *
 * arr[i1][i2][i3] = arr + (sizeof(double) * i1 * N2 * N3) + (sizeof(double)) * i2 * N3) + (sizeof(double) * i3) 
 * EQUATION: arr + sizeof(double) ((i1 * N2 * N3) + (i2 * N3) + (i3))		
 *
 * "+" in pointer aritmetic is already type sensitive: 
 * 												&double_var or double* + n = &double_var + n * sizeof(double) 
 *
 * Concluding that sizeof(double) is implicitly present in equation shown above
 *
 * EQUATION now becomes: arr + (i1 * N2 * N3) + (i2 * N3) + i3, i.e. 
 * arr + i1 * N2 * N3 + i2 * N3 + i3
 
 * Dereference that, 
 * *(arr + i1*N2*N3 + i2*N3 + i3) 
*/

#include <stdio.h> 
#include <stdlib.h> 

int main(void) {
	int array, row, column;
	double* arr = 0;
	
	printf("Enter array row column: ");
	scanf("%d %d %d", &array, &row, &column);
	
	arr = (double*)malloc(sizeof(double) * array * row * column);
	if(arr == NULL) {
		printf("fatal: out of memory");
		exit(EXIT_FAILURE);
	}
	memset(arr, 0, sizeof(double) * array * row * column);
		
	for(int i = 0; i < array; i++) {
		for(int j = 0; j < row; j++) {
			for(int k = 0; k < column; k++)
				printf("arr[%d][%d][%d]: %.2lf\t", i, j, k, *(arr + i * row * column + j * column + k));
			printf("\n");
		}
		printf("\n\n");
	}
	printf("\n\n\n");
		
	return (0);
}