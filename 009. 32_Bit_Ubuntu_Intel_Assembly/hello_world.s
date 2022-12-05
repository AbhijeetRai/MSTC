.section .rodata 
	message:
	.string	"Hello, World\n"

.section .text 
.globl main 
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
