#include <stdio.h> 
#include <stdlib.h> 

int arr[5] = {10, 20, 30, 40, 50}; 
int cnt; 

int main(void){
	cnt = 0; 
	while(cnt < 5){
		printf("arr[%d]:%d\n", cnt, arr[cnt]); 
		cnt += 1; 
	}
	puts("End of program"); 
	exit(0); 
}
