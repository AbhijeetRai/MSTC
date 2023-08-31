int test(void) {
	return (100);
}

/**
 * This function will be sneaked in as "data as code" in prg3.c 
 * In prg3.c we will place disassembly of this function (acting as malicious data) 
 * in heap. This is security vulnerabliity, we are placing malicious code as data in heap 
 * mammped memory. This is called as HEAP SPRAYING
 */


/* 
 * To generate machine code of given program, disassemble it: 
 * 	gcc -c func.c : func.o is created 
 *	objdump -D func.o > func.disasm
*/


/*
ubuntu@ubuntu-VirtualBox:~/MSTC/022. SP/05. Mmap$ cat func.disasm 
Disassembly of section .text:
00000000 <test>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	b8 64 00 00 00       	mov    $0x64,%eax
   8:	5d                   	pop    %ebp
   9:	c3                   	ret    
*/


/* 
	Place the shown machine code in prg3.c
	unsigned char data[] = {0x55, 0x89, 0xe5, 0xb8, 0x64, 0x00, 0x00, 0x00, 0x5d, 0xc3};
	
	We will map memory in heap, place this function data as code there and (execute) call it on heap
*/
