.section .rodata 
	end: 
	.string "End of code\n"

	output: 
	.string "n = %d\n"

	output2: 
	.string "eax = %d\n" 

.section .bss 
	.comm n, 4, 4 
	.comm i, 4, 4 

.section .data 
	.global inA 
	.type inA, @object 
	.size inA, 36
	.align 4 
	inA: 
		.int 0xa0b0c0d0 
		.int 0x10203040	
		.int 0xffc0ffd0 	
		.int 0xffa0ffb0
		.int 10, 20, 30, 40, 50 

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 
	
	movl $0, i
	jmp cond 

	loop:
		movl i, %eax
		movl $16, %ecx
		movl inA(%ecx, %eax, 4), %edi
		movl %edi, n
		
		pushl n 
		pushl $output 
		call printf 
		addl $8, %esp
 
		addl $1, i

	cond:
		cmpl $5, i
		jl loop 

	pushl $end 
	call puts 
	addl $4, %esp 
	
	pushl $0 
	call exit 
