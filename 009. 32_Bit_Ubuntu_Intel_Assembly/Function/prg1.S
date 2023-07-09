.section .rodata 
	msg1: 
	.string "Enter n1:"

	msg2: 
	.string "Enter n2:"

	add: 
	.string "%d + %d = %d\n"

	sub: 
	.string "%d - %d = %d\n"

	mul: 
	.string "%d * %d = %d\n"

	quo: 
	.string "%d / %d = %d\n"

	rem: 	
	.string "%d %% %d = %d\n"

	input: 
	.string "%d"

	output: 
	.string "%d\n"

.section .bss 
	.comm n1, 4, 4
	.comm n2, 4, 4
	.comm result, 4, 4

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 
	
	#Asking to enter n1
	pushl $msg1 
	call printf 
	addl $4, %esp
	
	#Accepting n1
	pushl $n1 
	pushl $input 
	call scanf 
	addl $8, %esp
	
	#Printing n1 
	pushl n1 
	pushl $output
	call printf 
	addl $8, %esp

	#Asking to enter n2
	pushl $msg2 
	call printf 
	addl $4, %esp
	
	#Accepting n2
	pushl $n2 
	pushl $input 
	call scanf 
	addl $8, %esp 

	#Printing n2
	pushl n2 
	pushl $output 
	call printf 
	addl $8, %esp
	
	pushl n2 
	pushl n1 
	call cpa_add 
	addl $8, %esp
	movl %eax, result	

	pushl result
	pushl n2 
	pushl n1 
	pushl $add 
	call printf 
	addl $16, %esp

	pushl n2 
	pushl n1 
	call cpa_sub 
	addl $8, %esp 
	movl %eax, result

	pushl result
	pushl n2 
	pushl n1 
	pushl $sub 
	call printf 
	addl $16, %esp

	pushl n2 
	pushl n1 
	call cpa_mul 
	addl $8, %esp 
	movl %eax, result 

	pushl result 
	pushl n2 
	pushl n1 
	pushl $mul 
	call printf 
	addl $8, %esp

	pushl n2 
	pushl n1 
	call cpa_rem
	addl $8, %esp 
	movl %eax, result 

	pushl result 
	pushl n2 
	pushl n1 
	pushl $rem 
	call printf 
	addl $8, %esp

	pushl n2 
	pushl n1 
	call cpa_quo
	addl $8, %esp 
	movl %eax, result 

	pushl result 
	pushl n2 
	pushl n1 
	pushl $quo
	call printf 
	addl $8, %esp

	movl %ebp, %esp 
	popl %ebp

.global cpa_add 
.type cpa_add, @function 
cpa_add: 
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp 	

	movl 8(%ebp), %eax 
	movl 12(%ebp), %ebx 
	addl %ebx, %eax 
	movl %eax, -4(%ebp)

	movl %ebp, %esp 
	popl %ebp 
	ret

.global cpa_sub 
.type cpa_sub, @function 	
cpa_sub: 
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp		
		
	movl 8(%ebp), %eax 
	movl 12(%ebp), %ebx 
	subl %ebx, %eax 
	movl %eax, -4(%ebp)

	movl %ebp, %esp 
	popl %ebp 
	ret

.global cpa_mul 
.type cpa_mul, @function 
cpa_mul:
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp	

	movl 8(%ebp), %eax 
	movl 12(%ebp), %ebx 
	mull %ebx
	movl %eax, -4(%ebp)

	movl %ebp, %esp 
	popl %ebp 
	ret

.global cpa_rem 
.type cpa_rem, @function 
cpa_rem: 
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp 

	movl 8(%ebp), %eax 
	movl 12(%ebp), %ebx
	#Remainder in edx, set edx to 0 to avoid floating point exception 
	movl $0, %edx	
	divl %ebx
	movl %edx, -4(%ebp)
	movl %edx, %eax		

	movl %ebp, %esp 
	popl %ebp 
	ret

.global cpa_quo 
.type cpa_quo, @function 
cpa_quo: 
	pushl %ebp 
	movl %esp, %ebp 
	subl $4, %esp 

	movl 8(%ebp), %eax 
	movl 12(%ebp), %ebx
	#Remainder in edx, set edx to 0 to avoid floating point exception 
	movl $0, %edx	
	divl %ebx
	movl %eax, -4(%ebp)

	movl %ebp, %esp 
	popl %ebp 
	ret
