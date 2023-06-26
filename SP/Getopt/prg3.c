#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define TRUE	1
#define FALSE	0 

void help(void); 
void version(void); 

int main(int argc, char* argv[]) {
	
	int flag = FALSE; 
	int s_flag = FALSE, d_flag = FALSE; 
	int ret; 

	char* source_path = NULL; 
	char* dest_path = NULL; 

	/*: stands for argument which is read in optarg*/
	while((ret = getopt(argc, argv, "hvs:d:")) != -1) {
		flag = TRUE; 
		switch((char)ret) {
			case 'h':
				help();
				break;
			case 'v':
				version();
				break;

			case 's':
				s_flag = TRUE;
				source_path = optarg;
				break; 
			
			case 'd':
				d_flag = TRUE;
				dest_path = optarg;
				break;
		}
	}

	if(flag == FALSE) {
		help();
		exit(EXIT_FAILURE);
	}

	if(s_flag != d_flag) {
		puts("Source or destination is missing");
		help();
		exit(EXIT_FAILURE);
	}

	printf("source_path=%s\ndestination_path=%s\n", source_path, dest_path);	
}

void help(void) {
	char* help_string = "cpacp -h\n\
	cpacp -v\n\
	cpacp -s SOURCE_PATH -d DEST_PATH\n\
	-h: for getting help\n\
	-v: for getting version\n\
	-s: for specifying source path(must exist)\n\
	-d: for specifying destination path";
	puts(help_string);
}

void version(void) {
	char* version_string = "0.1";
	puts(version_string);
}

