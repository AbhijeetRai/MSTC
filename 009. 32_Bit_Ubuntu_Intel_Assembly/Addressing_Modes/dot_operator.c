#include <stdio.h>
#include <stdio.h> 

struct Date {
	
	int day; 
	int month; 
	int year;
}; 

int dd, mm, yy; 
struct Date myDate = {1, 1, 1970}; 

int main(void) {
	dd = myDate.day; 
	mm = myDate.month; 
	yy = myDate.year; 	

	printf("%d-%d-%d\n", dd, mm, yy); 
	
	myDate.day = 2; 
	myDate.month = 9; 
	myDate.year = 1997; 

	dd = myDate.day; 
	mm = myDate.month; 
	yy = myDate.year; 	

	printf("%d-%d-%d\n", dd, mm, yy); 
	
	exit(0);
}
