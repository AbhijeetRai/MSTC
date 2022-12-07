ection .rodata 
	message:
	.string "HELLO, WORLD!\n"

.section .text 
.global main 
main:

	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$message 
	call	printf 
	addl	$4, %esp

	movl	$0, %eax 
	movl	%ebp, %esp 
	popl	%ebp 
	ret

