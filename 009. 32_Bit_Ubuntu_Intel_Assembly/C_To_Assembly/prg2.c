/*
	initialised global var: 		.data 
	initialised static global var:		.data 

	uninitialised global var:		.bss (.comm) common memory area accessible to all files)
	uninitialised static global var		.lcomm (local common memory area accessible to that file only)
*/

char c; 
unsigned char uc; 
short snum; 
unsigned short usnum; 
int inum; 
unsigned int uinum; 
long lnum; 
unsigned long ulnum; 
long long llnum; 
unsigned long long ullnum; 

int 	a[5]; 
short 	b[5];

struct Student { int st_roll; char* st_name; short marks };

struct Student st; 
struct Student st_arr[5];
