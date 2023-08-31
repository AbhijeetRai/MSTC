#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h>
#include <assert.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096 
/*
 * Typedef 
 *	"pointer to function: accepting void, returning int"
 * to function_t 
*/
typedef int(*function_t)(void);

int main(void) {
	
	function_t pfn; 
	int ret, sys_ret; 
	void* addr = NULL;

	unsigned char data[] = {0x55, 0x89, 0xe5, 0xb8, 0x64, 0x00, 0x00, 0x00, 0x5d, 0xc3};

	addr = mmap(NULL, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if(addr == (void*)-1) {
		printf("mmap:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	/*function's code put into heap now*/
	memcpy(addr, data, 15);
	
	/*Which is why we never give EXECUTE PERMISSION to data on heap*/
	/* It makes malicious data executable*/
	sys_ret = mprotect(addr, PAGE_SIZE, PROT_READ|PROT_EXEC);
	if(sys_ret == -1) {
		printf("mprotect:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	pfn = (function_t)addr;
	ret = pfn(); 
	printf("RET FROM FUNC = %d\n", ret);

	sys_ret = munmap(addr, PAGE_SIZE);
	assert(sys_ret != -1); 
	addr = NULL;
	
	exit(EXIT_SUCCESS);
}	

/* 
 * Default permission on process segments
 * rodata 	PROT_READ
 * data/bss	PROT_READ | PROT_WRITE 
 * stack 	PROT_READ | PROT_WRITE 
 * text 	PROT_READ | PROT_EXEC 
 * HEAP 	PROGRAMMER DEFINE 

 * PROT_NONE is also a permission
 */
