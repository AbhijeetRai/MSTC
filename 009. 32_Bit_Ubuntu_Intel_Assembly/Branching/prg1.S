.section .rodata 
	msg1:	
	.string "Enter n1:"
	
	msg2: 
	.string "Enter n2:"

	input: 
	.string "%d" 

	output: 
	.string "%d > %d\n"

	end: 
	.string "End of code\n"

.section .bss 
	.comm n1, 4, 4 
	.comm n2, 4, 4

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 
	
	#Ask to print n1
	pushl $msg1 
	call printf 
	addl $4, %esp
	
	pushl $n1 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to print n2
	pushl $msg2 
	call printf 
	addl $4, %esp

	pushl $n2 
	pushl $input 
	call scanf 
	addl $8, %esp

	movl n1, %eax 
	movl n2, %ebx 
	cmpl %ebx, %eax 
	jle out 
	
	L1: 	
		pushl n2 
		pushl n1
		pushl $output
		call printf 
		addl $12, %esp

	out: 
		pushl $end 
		call puts 
		addl $4, %esp
		pushl $0 
		call exit
