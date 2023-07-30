.section .rodata 
	input: 
	.string "Enter the number: "
	
	output: 
	.string "Entered number is: %d\n"
	
	input_format_specifier: 
	.string "%d"
	
	prime: 
	.string "Number is prime"

	composite: 
	.string "Number is composite"


.section .data 
	.global number 
	.type number, @object 
	.size number, 4 
	.align 4 
	number: 
	.int 0 

	.global half_of_number 
	.type half_of_number, @object 
	.size half_of_number, 4 
	.align 4 
	half_of_number: 
	.int 0 


.section .bss 
	.comm i, 4, 4


.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp	

	pushl $input 
	call printf 
	addl $4, %esp 

	pushl $number 
	pushl $input_format_specifier 
	call scanf 
	addl $8, %esp 
	
	pushl number 
	pushl $output 
	call printf 
	addl $8, %esp 
	
	movl number, %eax 
	movl $0, %edx	
	movl $2, %ebx 
	divl %ebx
	movl %eax, half_of_number 

	movl $2, i
	movl half_of_number, %esi
	jmp cond

	loop: 	
		movl number, %eax
		movl $0, %edx 
		movl i, %edi 
		divl %edi
		cmpl $0, %edx
		jne inc 
		movl $1, -4(%ebp)
		jmp break		
		
		inc:
			addl $1, i 

	cond: 
		cmpl %esi, i 
		jle loop

	break: 	
		movl -4(%ebp), %edx 		
		
		cmpl $1, %edx 
		jne prime_msg

		pushl $composite 
		call puts 
		addl $4, %esp
		jmp out

	prime_msg: 
		pushl $prime 
		call puts 
		addl $4, %esp
	
	out:
		movl %ebp, %esp 
		popl %ebp 
		ret
