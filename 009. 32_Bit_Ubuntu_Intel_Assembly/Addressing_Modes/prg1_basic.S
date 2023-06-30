#Addressing modes are way to access memory address 
#It is about how we access address of memory when it is an operand 

#Direct addressing mode is "pushl num" in code 
#Memory is directly given as operand 
#In our case num will be replaced with its memory address at machine code level 
#At machine code level, pushl num will be translated to pushl <some_memory_address_of_num>
#Use command objdump -D a.out > file.disasm to see dump

#Indirect addressing modes: In assembly, local variables of function, struct members and parameters of functions have no name 
#Hence they cannot be exactly pin pointed on memory directly with a variable name. To point such memories, indirect addressing mode is used 
#Memory cannot be referenced directly is pointed with help of register or memory. Here for example, movl $num, %eax 
#Address of memory pointed by num is moved to eax register. And later same memory is dereferenced/accesed with register. 
#It is register indirect addressing mode

.section .rodata 
	msg: 
	.string "num = %d\n"

.section .data 
	.global num 
	.type num, @object 
	.size num, 4 
	.align 4 	
	num: 
	.int 100

.section .text 
.global main 
.type main, @function
main: 
	pushl %ebp 
	movl %esp, %ebp 

	pushl num 
	pushl $msg 
	call printf 
	addl $8, %esp

	movl $num, %eax 
	movl $200, (%eax) 

	pushl num 
	pushl $msg 
	call printf 
	addl $8, %esp

	pushl $0 
	call exit
