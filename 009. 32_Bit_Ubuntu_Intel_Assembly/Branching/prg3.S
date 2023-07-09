.section .rodata 
	msg1: 
	.string "Enter a: "

	msg2: 
	.string "Enter b: "

	msg3: 
	.string "Enter m: "

	msg4: 
	.string "Enter n: "

	msg5: 
	.string "Enter x: "

	msg6: 
	.string "Enter y: "

	input: 
	.string "%d"

	output1:
	.string "a >= b"

	output2:
	.string "a < b and m < n"

	output3:
	.string "a < b and m >= n and x == y"

	output4: 
	.string "a < b and m >= n and x != y"

	end: 
	.string "End of code\n"


.section .bss
	.comm a, 4, 4
	.comm b, 4, 4
	.comm m, 4, 4
	.comm n, 4, 4	
	.comm x, 4, 4
	.comm y, 4, 4


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

	#Ask to input m and accept m
	pushl $msg3 
	call printf 
	addl $4, %esp
	pushl $m 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input n and accept n
	pushl $msg4 
	call printf 
	addl $4, %esp
	pushl $n 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input x and accept x
	pushl $msg5 
	call printf 
	addl $4, %esp
	pushl $x 
	pushl $input 
	call scanf 
	addl $8, %esp

	#Ask to input y and accept y
	pushl $msg6 
	call printf 
	addl $4, %esp
	pushl $y 
	pushl $input 
	call scanf 
	addl $8, %esp

	movl a, %eax 
	movl b, %ebx 
	cmpl %ebx, %eax 
	jl else_if1			#if a < b

	pushl $output1 
	call puts 
	addl $4, %esp 
	jmp out

	else_if1: 
		movl m, %eax 
		movl n, %ebx 
		cmpl %ebx, %eax 
		jge else_if2		#if m >= n
		
		pushl $output2 
		call puts 	
		addl $4, %esp 
		jmp out

	else_if2: 
		movl x, %eax 
		movl y, %ebx 
		cmpl %ebx, %eax 
		jne else 		#if x != y

		pushl $output3 
		call puts 	
		addl $4, %esp 
		jmp out

	else: 
		pushl $output4 
		call puts 
		addl $4, %esp 
		jmp out

	out: 
		pushl $end 
		call puts 
		addl $4, %esp
		pushl $0 
		call exit
