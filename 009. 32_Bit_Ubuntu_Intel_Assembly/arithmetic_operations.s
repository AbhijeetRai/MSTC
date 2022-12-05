.section .rodata 
	message1:
	.string	"Enter number1: "
	
	message2:
	.string "Enter number2: "
	
	message3:
	.string	"%d"

	message4:	
	.string	"\nThe sum is %d\n"
	
	message5:	
	.string	"The difference is %d\n"

	message6:
	.string "The multiplication is %d\n"
	
	message7:
	.string "The quotient is %d\n"

	message8:
	.string	"The remainder is %d\n"

.section .data 
	number1:
	.int 	0
	
	number2:
	.int	0 
	
	sum:
	.int 	0 

	sub: 
	.int 	0 

	mult:	
	.int	0 

	quotient:
	.int	0 

	remainder:
	.int 	0
	

.section .text 
.global main 
main:	
	pushl	%ebp 
	movl	%esp, %ebp 
	
	pushl	$message1
	call	printf 
	addl	$4, %esp	

	pushl	$number1
	pushl	$message3
	call	scanf	
	addl	$8, %esp

	pushl	$message2
	call	printf 
	addl	$4, %esp	

	pushl	$number2
	pushl	$message3
	call 	scanf
	addl	$8, %esp

	movl	number1, %eax 
	movl	number2, %edx 
	addl	%eax, %edx
	movl	%edx, sum 

	pushl	sum	
	pushl	$message4
	call	printf 
	addl	$8, %esp
	
	movl	number1, %eax
	movl	number2, %edx 
	subl	%edx, %eax 
	movl	%eax, sub
	
	pushl	sub
	pushl	$message5
	call	printf 
	addl	$8, %esp	

	movl	number1, %eax 
	movl	number2, %edx 
	mull	%edx
	movl	%eax, mult
	
	pushl	mult
	pushl	$message6
	call	printf 
	addl	$8, %esp

	movl	number1, %eax 
	movl	number2, %ebx
	movl	$0, %edx 
	divl	%ebx
	movl	%eax, quotient 
	movl	%edx, remainder 

	pushl	quotient 
	pushl	$message7
	call	printf 
	addl	$8, %esp

	pushl	remainder
	pushl	$message8
	call	printf 
	addl	$8, %esp	

	movl	$0, %eax
	movl	%ebp, %esp
	popl	%ebp
	ret
	
