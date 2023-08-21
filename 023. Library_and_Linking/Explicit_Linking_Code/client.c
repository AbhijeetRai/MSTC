#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h> 

//gcc client.c -ldl

int main(void) {
	
	const char* lib_path = "./libtest.so";
	
	/*library will be linked in ummaped virtual address space (heap)*/	
	void* lib_base_addr = NULL;
	void (*pfn1)(void); 
	void (*pfn2)(void);
	
	//get address of library from heap
	lib_base_addr = dlopen(lib_path, RTLD_NOW); 
	if(lib_base_addr == NULL) {
		printf("Error in loading %s:%s\n", lib_path, dlerror());	
		exit(EXIT_FAILURE);
	}

	pfn1 = dlsym(lib_base_addr,"function1");
	if(pfn1 == NULL) {
		printf("Error in loading function1:%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	pfn2 = dlsym(lib_base_addr, "function2"); 
	if(pfn2 == NULL) {
		printf("Error in loading function2:%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	pfn1(); 
	pfn2();
	
	//remvoe library from heap
	dlclose(lib_base_addr);
	pfn1 = NULL; 
	pfn2 = NULL; 
	
	exit(EXIT_SUCCESS);
}
