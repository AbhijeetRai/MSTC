#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define TRUE	1 
#define FALSE	0 

void help(void); 
void version(void);

int main(int argc, char* argv[]) {
	
	int ret; 
	int no_opt = FALSE; 
	
	if(argc == 1) {
		help();
		exit(EXIT_SUCCESS);
	}

	while((ret = getopt(argc, argv, "hv")) != -1) {
		no_opt = TRUE;
		switch((char)ret) {
			case 'h':
				help();
				break;
			case 'v':
				version();
				break;
			default: 
				help();
				printf("%c %d Invalid choice\n", (char)ret, ret);
		}
	}


	if(!no_opt) {
		help();
		exit(EXIT_FAILURE);
	}
}

void help(void) {
	char* str_help = "./app [-h/-v]\n\
			-h: for printing help\n\
			-v: for printing version";
	puts(str_help);
}

void version(void) {
	puts("0.1");
}
