.section .rodata 
	message:
	.string	"number = %d\n"

.section .data 
	number:
	.int	10 

.section .text 
.global main 
main:	
	pushl	%ebp 
	movl	%esp, %ebp 
	
	pushl	number
	pushl	$message
	call	printf 
	addl	$8, %esp

	movl	$0, %eax
	movl	%ebp, %esp
	popl	%ebp    	
	ret
