.section .rodata 
	output: 
		.string "arr[%d]:%d\n"

	msg1: 
		.string "End of break loop" 

	msg2: 
		.string "End of code"


.section .data 
	.global arr 
	.type arr, @object 
	.size arr, 32 
	.align 32 
	arr: 
		.int 4, 7, 1, 5, 8, 10, 15, 11 

.section .bss 
	.comm i, 4, 4

.section .text 
.global main 
.type main, @function 
main:
	pushl %ebp 
	movl %esp, %ebp
	
	movl $0, i 
	jmp cond1 
	
	loop1:  
		movl i, %edx
		movl arr(, %edx, 4), %eax
		movl %eax, %edi		
		
		movl $0, %edx
		movl $5, %esi
		divl %esi
		cmpl $0, %edx
		je break 

		pushl %edi  
		pushl i
		pushl $output 
		call printf 
		addl $12, %esp
		addl $1, i

	cond1: 
		cmpl $8, i 
		jl loop1 
	
	break:
		pushl $msg1 
		call puts 
		addl $4, %esp

	movl $0, i 
	jmp cond2 

	loop2: 
		movl i, %edx
		movl arr(, %edx, 4), %eax
		movl %eax, %edi

		movl $0, %edx
		movl $5, %esi
		divl %esi
		cmpl $0, %edx
		je increment 

		pushl %edi  
		pushl i
		pushl $output 
		call printf 
		addl $12, %esp

		increment: 
			addl $1, i

	cond2: 
		cmpl $8, i 
		jl loop2 

	pushl $msg2 
	call puts 
	addl $4, %esp	

	pushl $0
 	call exit 
