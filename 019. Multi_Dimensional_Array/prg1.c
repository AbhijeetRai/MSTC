#include <stdio.h>
#include <stdlib.h> 

int a[5][3];

int main(void) {
	int i;
	int j;

	printf("addr(a)=%llu\n\n", (unsigned long long)a);
	for(i = 0; i < 5; i++)
		printf("addr(a[%d]):%llu", i, (unsigned long long)&a[i]);

	for(i = 0; i < 5; i++) 
		for(j = 0; j < 4; j++) 
				printf("addr(a[%d][%d]):%llu\n", i, j, (unsigned long long)&a[i][j]);

	return (0);
}