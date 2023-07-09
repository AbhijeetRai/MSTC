.section .rodata 
	msg1: 
	.string "Enter a: "

	msg2: 
	.string "Enter b: "

	msg3: 
	.string "Enter c: "

	msg4: 
	.string "Enter d: "

	input: 
	.string "%d"

	output1:
	.string "a >= b and c < d"

	output2:
	.string "a >= b or c < d or both"

	end: 
	.string "End of code\n"


.section .bss
	.comm a, 4, 4
	.comm b, 4, 4
	.comm c, 4, 4
	.comm d, 4, 4

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 

	#Ask to input a and accept a
	pushl $msg1 
	call printf 
	addl $4, %esp
	pushl $a 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input b and accept b
	pushl $msg2 
	call printf 
	addl $4, %esp
	pushl $b 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input m and accept c
	pushl $msg3 
	call printf 
	addl $4, %esp
	pushl $c
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input n and accept d
	pushl $msg4 
	call printf 
	addl $4, %esp
	pushl $d
	pushl $input 
	call scanf 
	addl $8, %esp
	
	movl a, %eax 
	movl b, %ebx
	cmpl %ebx, %eax
	jl if2		#if a < b 
	movl c, %ecx 
	movl d, %edx
	cmpl %edx, %ecx
	jge if2		#if c >= d
	pushl $output1
	call puts 
	addl $4, %esp
	
	if2:   		
		cmpl %ebx, %eax 
		jl cond2	#if a < b
		pushl $output2
		call puts 
		addl $4, %esp
		jmp out

	cond2: 	
		cmpl %edx, %ecx
		jge out 	#if c >= d 
		pushl $output2
		call puts 
		addl $4, %esp
			
	
	out: 
		pushl $end 
		call puts 
		addl $4, %esp
		pushl $0 
		call exit
