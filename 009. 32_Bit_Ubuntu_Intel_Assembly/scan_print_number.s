.section .rodata 
	message1:
	.string	"Enter the number: "
	
	message2:
	.string	"%d"

	message3:
	.string	"The number is: "

.section .data 
	number:
	.int 	0

.section .text 
.global main 
main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	
	pushl	$message1
	call 	printf 
	addl	$4, %esp 

	pushl	$number
	pushl	$message2
	call 	scanf 
	addl	$8, %esp

	pushl	number
	pushl	$message2
	call 	printf
	addl	$8, %esp	

	movl	$0, %eax 
	movl	%ebp, %esp 
	popl	%ebp 
	ret
