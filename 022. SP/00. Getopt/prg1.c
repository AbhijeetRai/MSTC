extern int printf(const char*, ...);

int ind = 1;
int nest_ind = 1;

int in_source_string(char char_to_find, const char* source_string) {
	
	int i = 0;
	int flag = 0;

	while(source_string[i] != '\0') {
		//printf("%c %c\n", char_to_find, source_string[i]);
		if(source_string[i] == char_to_find) {
			flag = 1; 
			break;
		}
		i += 1;
	}
	return (flag);
}

int customgetopt(int argc, char** argv, const char* string) {
	
	while(ind != argc) {
		if((char)argv[ind][0] != '-') {
			ind += 1; 
			continue;	
		}
		else {
			if(argv[ind][nest_ind] == '\0') {
				ind += 1;
				nest_ind = 1;
				continue;
			}

			else if(in_source_string(argv[ind][nest_ind], string)) {
				nest_ind += 1;
				return ((int)argv[ind][nest_ind-1]);
			}
			else {
				printf("./a.out: invalid option -- %c\n", argv[ind][nest_ind]);
				nest_ind += 1;
				return 63;
			}
		}
	}
	
	return (-1);
}

int main(int argc, char* argv[]) {
	
	int ret = 0;
	while ((ret = customgetopt(argc, argv, "ab")) != -1) 
		printf("INSIDE LOOP: %d %c\n", ret, (char)ret);
	printf("OUTSIDE LOOP: %d %c\n", ret, (char)ret);
}
