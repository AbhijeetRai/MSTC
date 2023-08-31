#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <string.h> 
#include <sys/mman.h> 
#include <unistd.h>
#include <assert.h>

#define PAGE_SIZE 1024

int main(void) {
	
	void* addr = (void*)1610612736;
	int sys_ret; 

	addr = mmap(addr, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if(addr == (void*)-1) {
		printf("mmap:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("addr = %lu\n", (unsigned long int)addr);

	memset(addr, 'A', PAGE_SIZE);
	if(write(STDOUT_FILENO, addr, PAGE_SIZE) != PAGE_SIZE) {
		printf("write:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	sys_ret = munmap(addr, PAGE_SIZE);
	assert(sys_ret != -1); 
	addr = NULL;
	
	exit(EXIT_SUCCESS);
}
